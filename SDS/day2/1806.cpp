#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n, 0);
    for(auto &it: v) {
        cin >> it;
    }
    int s = 0, e= 0;
    int sum = 0;
    int ret = 100005;
    while(s < n) {
        if(s == e) {
            sum += v[e++];
            if(sum >= k) {
                ret = min(ret, e-s);
            }
        }
        while(e < n && sum <= k) {
            sum += v[e];
            if(sum >= k) {
                ret = min(ret, e-s+1);
            }
            e++;
        }
        sum -= v[s++];
        if(sum >= k && s != e) {
            ret = min(ret, e-s);
        }
    }
    if(ret > 100000) {
        ret = 0;
    }
    cout << ret << "\n";
}