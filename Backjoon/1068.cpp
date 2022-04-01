#include <bits/stdc++.h>
using namespace std;
int N, M;
int root = -1;
vector<vector<int> > c;
int search(int idx) {
    int ret = 1;
    int child = 0;
    for(auto next: c[idx]) {
        if(next == M) continue;
        child += search(next);
    }
    if(child) return child;
    else return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; c.resize(N);
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x == -1) { root = i; continue; }
        c[x].push_back(i);
    } 
    cin >> M;
    if(M == root) {
        cout << 0 << "\n";
        return 0;
    }
    cout << search(root) << "\n";
    return 0;
}