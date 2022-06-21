#include <bits/stdc++.h>
using namespace std;
int N;
long long cache[1000001];
long long sat(long long x) {
    string tmp = to_string(x);
    for(int j = 0; j < tmp.size()-1; j++) {
        if(tmp[j] <= tmp[j+1]) return pow(10, (tmp.size() - 1 - j));
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < 10; i++) {
        cache[i] = i;
    }
    cin >> N;
    int k = 10;
    for(long long x = 10; k <= N;) {
        long long ret = sat(x);
        if(ret == 0) {
            cache[k++] = x++;
        } else {
            x += ret;
            x -= (x % ret);
            if(x > 9876543210) break;
        }
    }
    cout << cache[N] << "\n";
}