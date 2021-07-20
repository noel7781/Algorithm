#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define PIVOT (1 << 3)

using namespace std;
typedef long long ll;

ll minTree[PIVOT * 2];
ll sumTree[PIVOT * 2];
ll ans = 0;

void update(int n, ll v) {
    n += PIVOT;
    minTree[n] = v;
    sumTree[n] = v;
    n /= 2;
    while(n > 0) {
        minTree[n] = min(minTree[n*2], minTree[n*2+1]);
        sumTree[n] = sumTree[n*2] + sumTree[n*2+1];
        ans = max(minTree[n], sumTree[n]);
        n /= 2;
    }
}

void query(int l, int r) {
    l += PIVOT; r += PIVOT;
    ll min_val = 1e9;
    ll sum_val = 0;
    while(l <= r) {
        if(l % 2 == 1) {
            min_val = min(min_val, minTree[l]);
            sum_val = sum_val + sumTree[l++];
        }
        if(r % 2 == 0) {
            min_val = min(min_val, minTree[r]);
            sum_val = sum_val + sumTree[r--];
        }
        l /= 2; r /= 2;
    }
    ans = max(ans, min_val * sum_val);
}

int main() {
    for(int i = 0; i < PIVOT*2; ++i) {
        minTree[i] = 1e8;
    }
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        ll val; cin >> val;
        update(i, val);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            query(i, j);
        }
    }
    // 시간 줄여야 가능
    cout << ans << "\n";
}