#include <bits/stdc++.h>
using namespace std;
int X, N;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> X) {
        int tar = X * 1e7;
        cin >> N;
        V.clear();
        V.resize(N);
        for(auto &it: V) cin >> it;
        sort(V.begin(), V.end());
        bool found = false;
        for(int i = 0; i < N; i++) {
            int now = V[i];
            int nxt = tar - now;
            if(nxt <= 0) break;
            auto lit = lower_bound(V.begin(), V.end(), nxt);
            auto uit = upper_bound(V.begin(), V.end(), nxt);
            if(lit != V.end() && *lit == nxt) {
                if(lit - V.begin() > i || lit - V.begin() == i && uit - lit > 1) {
                    found = true;
                    cout << "yes " << now << " " << nxt << "\n";
                    break;
                }
            }
        }
        if(!found) {
            cout << "danger\n";
        }
    }
}