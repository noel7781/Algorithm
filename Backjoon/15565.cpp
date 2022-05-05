#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int N, K;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x == 1) V.push_back(i);
    }
    int len = V.size();
    if(len < K) {
        cout << -1 << "\n";
        return 0;
    }
    int ret = 1e9;
    int l = 0, r = 0;
    int cur = 0;
    while(r < len) {
        cur++;
        if(cur == K) {
            ret = min(ret, V[r]-V[l]+1);
            l++;
            cur--;
        }
        r++;
    }
    cout << ret << "\n";
}