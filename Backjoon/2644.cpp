#include <bits/stdc++.h>
using namespace std;
int N; int p1, p2;
int M;
int parent[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> p1 >> p2 >> M;
    for(int i = 0; i < M; i++) {
        int p, c; cin >> p >> c;
        parent[c] = p;
    }
    int d1 = 0, d2 = 0;
    int tmp = p1;
    while(parent[tmp]) {
        tmp = parent[tmp];
        d1++;
    }
    tmp = p2;
    while(parent[tmp]) {
        tmp = parent[tmp];
        d2++;
    }
    if(d1 < d2) { swap(p1, p2); swap(d1, d2); }
    int ret = 0;
    int diff = d1 - d2;
    while(diff) {
        p1 = parent[p1];
        diff--;
        ret++;
    }
    if(p1 == p2) {
        cout << ret << "\n";
        return 0;
    }
    while(1) {
        if(p1 == p2) break;
        p1 = parent[p1];
        p2 = parent[p2];
        ret += 2;
    }
    if(p1 == 0) cout << -1 << "\n";
    else cout << ret << "\n";

}