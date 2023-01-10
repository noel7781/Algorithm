#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> A, B;

int cache[2001][2001];

int solve(int l, int r) {
    if(l >= n || r >= n)
        return 0;
    int& ret = cache[l][r];
    if(ret != -1)
        return ret;
    ret = 0;
    ret = max(solve(l+1, r+1), solve(l+1, r));
    if(A[l] > B[r]) {
        ret = max(ret, B[r] + solve(l, r+1));
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    A.assign(n, 0);
    B.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    cout << solve(0, 0) << "\n";
}
