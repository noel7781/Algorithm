#include <bits/stdc++.h>
using namespace std;
int D, K;
int A, B;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> D >> K;
    int p[] = {1, 0};
    int q[] = {0, 1};
    int sum[] = {0, 0};
    for(int k = 3; k <= D; k++) {
        for(int s = 0; s < 2; s++) {
            sum[s] = p[s] + q[s];
            p[s] = q[s];
            q[s] = sum[s];
        }
    }
    for(int s = 1; s < (K / sum[0]); s++) {
        int left = K - sum[0] * s;
        if(left % sum[1] == 0) {
            A = s;
            B = (left / sum[1]);
            break;
        }
    }
    cout << A << "\n" << B << "\n";
}