#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll cache[91];

ll fib(int n) {
    if(n <= 1) return n;
    ll& ret = cache[n];
    if(ret != -1) return ret;
    return ret = fib(n-1) + fib(n-2);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << fib(n) << "\n";
}