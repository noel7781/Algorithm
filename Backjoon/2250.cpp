#include <bits/stdc++.h>
using namespace std;
int N;
struct Node {
    int left;
    int right;
};
int min_values[10001];
int max_values[10001];
int orders = 1;
bool ins[10001];
vector<Node> nodes;
void dfs(int root, int depth) {
    if(nodes[root].left != -1) {
        dfs(nodes[root].left, depth+1);
    } 
    int pos = orders++;
    min_values[depth] = min(min_values[depth], pos);
    max_values[depth] = max(max_values[depth], pos);
    if(nodes[root].right != -1) {
        dfs(nodes[root].right, depth+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    nodes.resize(N+1);
    memset(min_values, 0x3f, sizeof(min_values));
    memset(max_values, 0, sizeof(max_values));
    for(int i = 0; i < N; i++) {
        int node_num, l, r; cin >> node_num >> l >> r;
        nodes[node_num].left = l;
        nodes[node_num].right = r;
        ins[l] = 1;
        ins[r] = 1;
    }
    int root = 1;
    for(int i = 1; i <= N; i++) {
        if(!ins[i]) {
            root = i;
            break;
        }
    }
    dfs(root, 1);
    int diff_max = 0;
    int diff_max_idx = 1;
    for(int i = 1; i <= 10000; i++) {
        if(diff_max < max_values[i] - min_values[i]) {
            diff_max = max_values[i] - min_values[i];
            diff_max_idx = i;
        }
    }
    cout << diff_max_idx << " " << diff_max+1 << "\n";
}