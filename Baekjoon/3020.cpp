#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, h;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    vector<int> d(n/2), u(n/2);
    for(int i = 0; i < n/2; ++i) {
        cin >> d[i] >> u[i];
    }
    sort(d.begin(), d.end());
    sort(u.begin(), u.end());

    int min_destroy = 1e9;
    int count = 1;
    for(int H = 1; H <= h; ++H) {
        int downside = n/2 - (upper_bound(d.begin(), d.end(), H-1) - d.begin()) ;
        int upside = u.end() -  (lower_bound(u.begin(), u.end(), h-H+1));
        int ret = downside + upside;
        if(ret < min_destroy) {
            min_destroy = ret;
            count = 1;
        } else if(ret == min_destroy) {
            count += 1;
        }
    }
    cout << min_destroy << " " << count << "\n";
}
