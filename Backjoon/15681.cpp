#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int num;
    vector<Node*> child;
    Node(int num): num(num), child(vector<Node*>()) {}
};

int n, r, q;

vector<vector<int> > adj;
vector<bool> use;

int cache[100003];

void getTree(vector<Node*> tree, int parent) {
    use[parent] = true;
    for(int i = 0; i < adj[parent].size(); ++i) {
        int next = adj[parent][i];
        if(!use[next]) {
            tree[parent]->child.push_back(tree[next]);
            getTree(tree, next);
        }
    }
}

int getCount(vector<Node*> tree, int n) {
    int& ret = cache[n];
    if(ret != -1) return ret;
    ret = 1;
    Node* now = tree[n];
    for(int i = 0; i < now->child.size(); ++i) {
        ret += getCount(tree, now->child[i]->num);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> r >> q;
    adj.assign(n, vector<int>());
    use.assign(n, false);
    vector<Node*> tree(n, 0);
    for(int i = 0; i < n; ++i) {
        tree[i] = new Node(i);
    }
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    getTree(tree, r-1);
    getCount(tree, r-1);
    for(int i = 0; i < q; ++i) {
        int k; cin >> k;
        cout<< getCount(tree, k-1) << "\n";
    }
}
