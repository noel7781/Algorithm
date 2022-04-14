#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q;
vector<int> A;
vector<int> B;
int I, J, K;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; A.resize(N); B.resize(N);
    for(auto &it: A) cin >> it;
    for(auto &it: B) cin >> it;
    cin >> Q;
    while(Q--) {
        cin >> I >> J >> K;
        ll lo = 0, hi = (ll)INT_MAX;
        while(lo+1 < hi) {
            int mid = int((lo+hi)/2);
            int Acnt = upper_bound(A.begin(), A.end(), mid) - A.begin();
            Acnt = min(Acnt, I);
            int Bcnt = upper_bound(B.begin(), B.end(), mid) - B.begin();
            Bcnt = min(Bcnt, J);
            if(Acnt + Bcnt == K) {
                if(A[Acnt-1] > B[Bcnt-1]) {
                    cout << 1 << " " << Acnt << "\n";
                } else {
                    cout << 2 << " " << Bcnt << "\n";
                }
                break;
            }
            if(Acnt + Bcnt > K) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
    }

}