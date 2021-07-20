#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &x: v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    cout << v[k-1] << "\n";
}
