#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K; V.resize(N); for(auto &it: V) cin >> it;
    int ret = -1e9;
    int sum = 0;
    for(int i = 0; i < K; i++) {
        sum += V[i];
    }
    ret = max(ret, sum);
    for(int j = K; j < N; j++) {
        sum += V[j];
        sum -= V[j-K];
        ret = max(ret, sum);
    }
    cout << ret << "\n";
}