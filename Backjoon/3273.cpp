#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;

int solve(vector<int>& v) {
    int left = 0, right = n-1;
    int ret = 0;
    while(left <= right) {
        if(left != right) {
            if(v[left] + v[right] == x) {
                ret += 1;
                left += 1;
            } else if(v[left] + v[right] > x) {
                right -= 1;
            } else {
                left += 1;
            }
        } else {
            if(v[left] == x) {
                ret += 1;
            }
            left += 1;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> x;
    cout << solve(v) << "\n";
}
