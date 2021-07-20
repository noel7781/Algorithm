#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> save;

void dfs(int here) {
    cout << "DFS visits " << here+1 << endl;
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        if(!visited[there])
            dfs(there);
    }
    save.push_back(here+1);
}

void dfsAll() {
    visited.assign(adj.size(), 0);
    for(int i = 0; i < adj.size(); ++i) {
        if(!visited[i])
            dfs(i);
    }
}

int main() {
    // adj.assign(10, vector<int>(10, 0));
    adj.assign(10,vector<int>(0));
    int size; cin >> size;
    for(int i = 0; i < size; ++i) {
        int a,b; cin >> a >> b;
        // adj[a-1][b-1]= 1;
        adj[a-1].push_back(b-1);
    }
    dfsAll();
    cout << "topo\n";
    for(int i = save.size() - 1; i >= 0; --i) {
        cout << save[i] << " ";
    }
    return 0;
}
