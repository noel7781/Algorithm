#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    int l = 0, r = N-1;
    int a1 = 0, a2 = 0;
    int ret = INT_MAX;
    while(l < r) {
        int sum = V[l] + V[r];
        if(ret > abs(sum)) {
            ret = abs(sum);
            a1 = V[l]; a2 = V[r];
        }
        if(sum > 0) {
            r--;
        } else {
            l++;
        }
    }
    cout << a1 << " " << a2 << "\n";
}