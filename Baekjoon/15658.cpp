#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int ops[4];
int max_v = -1e9;
int min_v = 1e9;

void solve(vector<int>& v, int val, int pos, int ops[]) {
    if(pos == n) {
        if(val > max_v) max_v = val;
        if(val < min_v) min_v = val;
        return;
    }
    for(int i = 0; i < 4; ++i) {
        if(ops[i] > 0) {
            ops[i] -= 1;
            if(i == 0) {
                solve(v, val+v[pos], pos+1, ops);
            } else if(i == 1) {
                solve(v, val-v[pos], pos+1, ops);
            } else if(i == 2) {
                solve(v, val*v[pos], pos+1, ops);
            } else {
                solve(v, val/v[pos], pos+1, ops);
            }
            ops[i] += 1;
        }
    }

}

int main() {
    memset(ops, 0, sizeof(ops));
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for(int i = 0; i < 4; ++i) {
        cin >> ops[i];
    }
    solve(v, v[0], 1, ops);
    cout << max_v << "\n" << min_v << "\n";
}
