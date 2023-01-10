#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
ll cache[31];

ll A(int n) {
    if(n & 1) return 0;
    if(n == 2) return 3;
    ll& ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    ret += 3*A(n-2);
    for(int k = n-4; k >= 2; k -= 2) {
        ret += 2*A(k);
    }
    ret += 2; 
    return ret;

}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << A(n) << "\n";
}
