#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > adj;
vector<int> seen, order;

void makeGraph(vector<string>& v) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    for(int i = 0; i < v.size()-1; ++i) {
        if(v[i+1].find(v[i]) == 0) continue;
        int len = min(v[i].size(), v[i+1].size());
        for(int j = 0; j < len; ++j) {
            if(v[i][j] != v[i+1][j]) {
                int a = v[i][j] - 'a';
                int b = v[i+1][j] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
    /*
    for(int j = 1; j < v.size(); ++j) {
        int i = j-1, len = min(v[i].size(), v[j].size());
        for(int k = 0; k < len; ++k) {
            if(v[i][k] != v[j][k]) {
                int a = v[i][k] - 'a';
                int b = v[j][k] - 'a';
                adj[a][b] = 1;
                cout<<"a:"<<a<<" b:"<<b<<endl;
                break;
            }
        }
    }
    */
}

void dfs(int here) {
    seen[here] = 1;
    for(int there = 0; there < adj[here].size(); ++there) {
        if(adj[here][there] && !seen[there])
            dfs(there);
    }
    order.push_back(here);
}

vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for(int i = 0; i < m; ++i)
        if(!seen[i])
            dfs(i);
    reverse(order.begin(), order.end());
    for(int i = 0; i < m; ++i) {
        for(int j = i+1; j < m; ++j) {
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}

void solve(vector<string>& v) {
    makeGraph(v);
    vector<int> result = topologicalSort();
    if(result.empty()) {
        cout << "INVALID HYPOTHESIS\n";
    } else {
        for(auto &x: result) {
            cout << char(x+'a');
        }
        cout << "\n";
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        vector<string> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        solve(v);
    }
}
