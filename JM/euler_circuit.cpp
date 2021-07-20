#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
void getEulerCircuit(int here, vector<int>& circuit) {
    cout<<"here:"<<here<<endl;
    for(int there = 0; there < adj[here].size(); ++there) {
        while(adj[here][there] > 0) {
            adj[here][there]--;
            // adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

int main() {
    adj.assign(8, vector<int>(8, 0));
    int size; cin >> size;
    while(size--) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        // adj[b][a] = 1;
    }
    vector<int> res;
    getEulerCircuit(0, res);
    for(int i = res.size()-1; i >= 0; --i) {
        cout<< res[i] << " ";
    }
}