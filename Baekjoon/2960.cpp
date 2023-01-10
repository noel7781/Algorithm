#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k;

int isPrime[1001];

int solve() {
    int ret = 0;
    int cnt = 0;
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; i*j <= n; ++j) {
            if(isPrime[i*j]) {
                isPrime[i*j] = 0;
                cnt += 1;
                if(cnt == k) 
                    return i*j;
            }
        }
    }
    return 0;
}

int main() {
    memset(isPrime, 1, sizeof(isPrime));
    cin >> n >> k;
    cout << solve() << "\n";
}
