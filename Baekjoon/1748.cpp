#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 0;
    int cnt = 0;
    int tmp = n;
    while(tmp > 0) {
        int digits = tmp % 10;
        tmp -= digits;
        tmp /= 10;
        cnt += 1;
    }
    for(int k = 1; k < cnt; ++k) {
        ret += k* int(pow(10, k) - pow(10, k-1));
    }
    ret += (n - pow(10, cnt-1) + 1) * cnt;
    cout << ret << "\n";
    return 0;
}

