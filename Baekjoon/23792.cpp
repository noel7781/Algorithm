#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, Q;
vector<int> A;
vector<int> B;
vector<int> C;
int X, Y, Z, K;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; A.resize(N); B.resize(N); C.resize(N);
    for(auto &it: A) cin >> it;
    for(auto &it: B) cin >> it;
    for(auto &it: C) cin >> it;
    cin >> Q;
    while(Q--) {
        cin >> X >> Y >> Z >> K;
        ll lo = 0, hi = (ll)INT_MAX;
        while(lo+1 < hi) {
            int mid = int((lo+hi)/2);
            int Acnt = upper_bound(A.begin(), A.end(), mid) - A.begin();
            Acnt = min(Acnt, X);
            int Bcnt = upper_bound(B.begin(), B.end(), mid) - B.begin();
            Bcnt = min(Bcnt, Y);
            int Ccnt = upper_bound(C.begin(), C.end(), mid) - C.begin();
            Ccnt = min(Ccnt, Z);
            if(Acnt + Bcnt + Ccnt == K) {
                if(A[Acnt-1] > B[Bcnt-1] && A[Acnt-1] > C[Ccnt-1]) {
                    cout << 1 << " " << Acnt << "\n";
                } else if(B[Bcnt-1] > A[Acnt-1] && B[Bcnt-1] > C[Ccnt-1]) {
                    cout << 2 << " " << Bcnt << "\n";
                } else {
                    cout << 3 << " " << Ccnt << "\n";
                }
                break;
            }
            if(Acnt + Bcnt + Ccnt > K) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
    }

}