#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, B, C;
vector<int> A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; A.resize(N); for(auto &it: A) cin >> it;
    cin >> B >> C;
    ll ret = 0;
    for(auto s: A) {
        if(s >= B) {
            ret++;
            s -= B;
            ret += s / C + !!(s % C);
        } else {
            ret++;
        }
    }
    cout << ret << "\n";
}