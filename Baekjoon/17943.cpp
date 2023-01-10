#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[200002];

void pre_compute(vector<int>& dom, int N) {
    cache[0] = 0;
    for(int i = 1; i <= N; ++i) {
        cache[i] = dom[i-1] ^ cache[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    int N, Q; cin >> N >> Q;
    vector<int> dom;
    dom.assign(N-1, 0);
    for(int i = 0; i < N-1; ++i) {
        cin >> dom[i];
    }
    pre_compute(dom, N-1);
    while(Q--) {
        int q, x, y, d;
        int res = 0;
        cin >> q;
        if(q == 0) {
            cin >> x >> y;
            res = cache[x-1] ^ cache[y-1];
            cout << res << "\n";
        } else {
            cin >> x >> y >> d;
            res = cache[x-1] ^ cache[y-1];
            res ^= d;
            cout << res << "\n";
        }
    }
}