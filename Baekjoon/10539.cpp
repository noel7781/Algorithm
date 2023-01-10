#include <bits/stdc++.h>
using namespace std;
int N;
vector<long long> B;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; B.resize(N); for(auto &it: B) cin >> it;
    long long cur = 0; 
    for(int i = 0; i < N; i++) {
        long long tmp = B[i] * (i+1);
        cout << tmp - cur << " ";
        cur = tmp;
    }
    cout << "\n";
    return 0;
}