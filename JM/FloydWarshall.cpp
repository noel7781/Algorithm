#include <iostream>

using namespace std;

#define MAX_V 500

/* Solution1. High memory waste(V*V*V)
int V;
ing adj[MAX_V][MAX_V];
int C[MAX_V][MAX_V][MAX_V];
void allPairShortestPath1() {
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            if(i != j) {
                C[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
            } else {
                C[0][i][j] = 0;
            }
        }
    }
    for(int k = 1; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                C[k][i][j] = min(C[k-1][i][j], C[k-1][i][k] + C[k-1][k][j]);
            }
        }
    }
}
*/
/*Solution2. Memory (V*V) version*/
int V;
int adj[MAX_V][MAX_V];
void floyd() {
    for(int i = 0; i < V; ++i) adj[i][i] = 0;
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}
