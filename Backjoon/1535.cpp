#include <bits/stdc++.h>
using namespace std;
int N;
int L[21];
int J[21];
int cache[101][21];
int solve(int left, int pos) {
    if(pos == N) return 0;
    int& ret = cache[left][pos];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, solve(left, pos+1));
    if(left > L[pos]) ret = max(ret, J[pos] + solve(left-L[pos], pos+1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> L[i];
    for(int i = 0; i < N; i++) cin >> J[i];
    cout << solve(100, 0);
}