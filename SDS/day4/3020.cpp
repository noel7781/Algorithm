#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, h;

vector<int> d, u;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    d.assign(n/2, 0); u.assign(n/2, 0);
    for(int i = 0; i < n/2; ++i) {
        cin >> d[i] >> u[i];
        u[i] = h - u[i] + 1;
    }
    sort(d.begin(), d.end());
    sort(u.begin(), u.end());
    int min_dest = 1e9;
    int count = 1;
    for(int H=1; H <= h; ++H) {
        int down = (n / 2) - (lower_bound(d.begin(), d.end(), H) - d.begin());
        int up = (upper_bound(u.begin(), u.end(), H) - u.begin());
        if(min_dest > up+down) {
            min_dest = up+down;
            count = 1;
        } else if(min_dest == up+down) {
            count += 1;
        }
    }
    cout << min_dest << " " << count << "\n";

}