#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MOD = 10;

int pow(int a, int b) {
    if(b==1) return a % MOD;
    int ret = pow(a, b/2) % MOD;
    if(b%2) {
        int ret = pow(a, b/2) % MOD;
        return (ret * ret * a) % MOD;
    }
    return (ret * ret) % MOD;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        int ret = pow(a, b) % MOD;
        if(ret == 0) ret = 10;
        cout << ret << "\n";
    }

}
