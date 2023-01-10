#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int K;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K;
    vector<pii> v;
    for(int i = 0; i < 6; i++) {
        int x, y; cin >> x >> y; v.push_back({x, y});
    }
    int l1 = 0, l2 = 0;
    for(int i = 0; i+1 < 6; i += 2) {
        if(v[i].second > l1) l1 = v[i].second;
        if(v[i+1].second > l2) l2 = v[i+1].second;
    }
    int k = 0;
    for(; k < 6; k++) {
        if(v[(k)%6].second + v[(k+2)%6].second == v[(k+4)%6].second 
        && v[(k+1)%6].second + v[(k+3)%6].second == v[(k+5)%6].second) {
            break;
        }
    }
    cout << K * (l1 * l2 - (v[(k+1)%6].second * v[(k+2)%6].second)) << "\n";
}