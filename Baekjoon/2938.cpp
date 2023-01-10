#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > V(3, vector<int>());
int len[3];
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        V[x%3].push_back(x);
    }
    for(int i = 0; i < 3; i++) len[i] = V[i].size();
    int left = len[0];
    if(len[0] > (N+1)/2 || (len[0] == 0 && len[1] > 0 && len[2] > 0)) {
        cout << -1 << "\n";
    } else {
        for(int j = 0; j < len[1]; j++) {
            if(left > 1) {
                cout << V[0].back() << " ";
                left--;
                V[0].pop_back();
            }
            cout << V[1][j] << " ";
        }
        if(left > 0) {
            cout << V[0].back() << " ";
            V[0].pop_back();
            left--;
        }
        for(int j = 0; j < len[2]; j++) {
            cout << V[2][j] << " ";
            if(left > 0) {
                cout << V[0].back() << " ";
                left--;
                V[0].pop_back();
            }
        }
    }
}