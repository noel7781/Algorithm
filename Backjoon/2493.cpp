#include <bits/stdc++.h>
using namespace std;
int N;
stack<pair<int, int> > S;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    vector<int> ans(N, 0);
    for(int i = N-1; i >= 0; i--) {
        int now = V[i];
        if(!S.empty()) {
            while(!S.empty()) {
                auto [top, idx] = S.top();
                if(top <= now) {
                    ans[idx] = i+1;
                    S.pop();
                } else {
                    break;
                }
            }
        }
        S.push({now, i});
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}