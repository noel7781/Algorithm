#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using ull = unsigned long long;
const int MOD = 1000000007;

ull A[101];
ull B[101];

ull solve_A(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    ull& ret = A[n];
    if(ret != -1)
        return ret;
    return ret = (solve_A(n-1) % MOD + solve_A(n-2) % MOD + MOD) % MOD;
}

ull solve_B(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(n == 3)
        return 1;
    if(n == 4)
        return 3;
    ull& ret = B[n];
    if(ret != -1)
        return ret;
    if(n % 2)
        return ret = A[n / 2];
    return ret = (solve_B(n-2) % MOD + solve_B(n-4) % MOD + MOD) % MOD;
}

int main() {
    int t_cnt; cin >> t_cnt;
    while(t_cnt--) {
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        int n; cin >> n;
        cout << (solve_A(n) - solve_B(n) + MOD) % MOD << "\n";
    }
}
