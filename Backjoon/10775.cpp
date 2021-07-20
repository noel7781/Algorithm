#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int gates[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(gates, 0, sizeof(gates));
    int G, P; cin >> G >> P;
    int ret = 0;
    bool is_done = false;
    for(int i = 0; i < P; ++i) {
        int k; cin >> k;
        while(k > 0 && gates[k] > 0) {
            int t = gates[k];
            gates[k]++;
            k -= t;
        }
        if(k <= 0) {
            is_done = true;
        } else {
            if(!is_done) {
                gates[k]++;
                ret += 1;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
