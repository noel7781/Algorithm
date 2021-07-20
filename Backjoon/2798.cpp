#include <iostream>
#include <vector>

using namespace std;

int n, m;

int solve(vector<int>& v, int itemCount, int pos) {
    if(itemCount == 3) {
        return 0;
    }
    if(pos == n) {
        return -1e9;
    }
    int ret = 0;
    ret = solve(v, itemCount, pos+1);
    int cand = solve(v, itemCount+1, pos+1) + v[pos];
    if(cand <= m) {
        ret = max(ret, cand);
    }
    return ret;
}

int main() {
    cin >> n >> m;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(v, 0, 0) << "\n";
}
