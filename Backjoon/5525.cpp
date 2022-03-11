#include <bits/stdc++.h>
using namespace std;
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    string str; cin >> str;
    int sum = 0;
    int pow = 1;
    int ans = 0;
    int tar = 0;
    for(int i = 0; i < 2*N+1; i++) {
        if(i % 2 == 0) {
            tar += ('I' - 'A') * pow;
        } else {
            tar += ('O' - 'A') * pow;
        }
        pow *= 27;
    }
    pow = 1;
    for(int i = 0; i + (2*N+1) <= M; i++) {
        if(i == 0) {
            for(int j = 2*N; j >= 0; j--) {
                sum += ((str[j] - 'A') * pow);
                if(j != 0) pow *= 27;
            }
        } else {
            sum = (sum - (str[i-1] - 'A') * pow) * 27 + (str[i+2*N] - 'A');
        }
        if(sum == tar) {
            ans++;
        }
    }
    cout << ans << "\n";
}