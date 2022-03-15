#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int N, M;
vector<int> A, B;
vector<int> lpsum, rpsum;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll ret = 0;
    cin >> T;
    cin >> N; A.resize(N); for(auto &it: A) cin >> it;
    cin >> M; B.resize(M); for(auto &it: B) cin >> it;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = i; j < N; j++) {
            sum += A[j];
            lpsum.push_back(sum);
        }
    }

    for(int i = 0; i < M; i++) {
        int sum = 0;
        for(int j = i; j < M; j++) {
            sum += B[j];
            rpsum.push_back(sum);
        }
    }
    sort(rpsum.begin(), rpsum.end());
    for(auto num: lpsum) {
        auto bounds = equal_range(rpsum.begin(), rpsum.end(), T-num);
        ret += ll(bounds.second - bounds.first);
    }
    cout << ret << "\n";
}