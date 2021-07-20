#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ret = 0;
    int n, m; cin >> n >> m;
    vector<int> v(n, 0);
    for(auto &it: v) {
        cin >> it;
    }
    int sum = 0;
    int s = 0, e = 0;
    for(int s = 0; s < n; ++s) {
        while(sum <= m && e < n) {
            sum += v[e++];
            if(sum == m) {
                ret++;
            }
        }
        sum -= v[s];
        if(sum == m) {
            ret++;
        }
    }
    cout << ret << "\n";
}