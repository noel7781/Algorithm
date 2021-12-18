#include <iostream>
#include <vector>

#define MAX_V 1000

using namespace std;

int V;
int adj1[MAX_V][MAX_V];
int C[MAX_V][MAX_V][MAX_V];

// 인접 행렬에서 두 정점 사이에 간선이 없는 경우 아주 큰 값을 넣어 둔다.
void allPairShortestPath1() {
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            if(i != j)
                C[0][i][j] = min(adj1[i][j], adj1[i][0] + adj1[0][j]);
            else
                C[0][i][j] = 0;
        }
    }
    for(int k = 1; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                C[k][i][j] = min(C[k-1][i][j], C[k-1][i][k] + C[k-1][k][j]);
        }
    }
}


int adj2[MAX_V][MAX_V];

void floyd() {
    for(int i = 0; i < V; ++i) adj2[i][i] = 0;
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                adj2[i][j] = min(adj2[i][j], adj2[i][k] + adj2[k][j]);
            }
        }
    }
}


// u->v로 가는 가중치로 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
// via[u][v] : u에서 v까지 가는 최단경로가 경유하는 점 중 가장 번호가 큰 정점으로 -1로 초기화해 둔다.
int via[MAX_V][MAX_V];

void floyd2() {
    for(int i = 0; i < V; ++i) adj[i][i] = 0;
    memset(via, -1, sizeof(via));
    for(int k = 0; k < V; ++k)
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j)
                if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    via[i][j] = k;
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
}

void reconstruct(int u, int v, vector<int>& path) {
    if(via[u][v] == -1) {
        path.push_back(u);
        if(u != v) path.push_back(v);
    } else {
        int w = via[u][v];
        reconstruct(u, w, path);
        // w가 중복으로 들어가므로 지운다.
        path.pop_back();
        reconstruct(w, v, path);
    }
}
