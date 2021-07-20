#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

int t;
int l, r; 
int cache[102][102];

int solve(vector<int>& v_l, vector<int>& v_r, int lpos, int rpos, int mini) {
    int& ret = cache[lpos][rpos];
    if(ret != -1) 
        return ret;
    ret = 0;
    for(int p = lpos+1; p <= l; p++) {
        if(v_l[p] > mini)
            ret = max(ret, 1+solve(v_l, v_r, p, rpos, v_l[p]));
    }

    for(int p = rpos+1; p <= r; p++) {
        if(v_r[p] > mini)
            ret = max(ret, 1+solve(v_l, v_r, lpos, p, v_r[p]));
    }
    return ret;
}

int main() {
    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> l >> r;
        vector<int> v_l(l+1, 0);
        vector<int> v_r(r+1, 0);
        for(int i = 1; i <= l; ++i) {
            cin >> v_l[i];
        }
        for(int i = 1; i <= r; ++i) {
            cin >> v_r[i];
        }
        cout << solve(v_l, v_r, 0, 0, numeric_limits<int>::min()) << "\n";
    }
}
