#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int solve() {
    int ret = 0;
    sort(arr.begin(), arr.end());
    auto it = arr.begin();
    while(it+1 != arr.end()) {
        int adder = *(it) + *(it + 1);
        ret += adder;
        it = arr.erase(it);
        it = arr.erase(it);
        arr.push_back(adder);
        sort(arr.begin(), arr.end());
    }
    return ret;
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> n;
        arr.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << solve() << "\n";
    }
}
