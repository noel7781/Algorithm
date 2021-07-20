#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;

int solve(int start, int end, int k) {
    int size = end - start;
    if(size + 1 <= k) {
        return 0;
    }
    priority_queue<int> sub;
    for(int i = 0; i < size; ++i) {
        sub.push(v[i+1] - v[i]);
    }
    for(int i = 0; i < k-1; ++i) {
        sub.pop();
    }
    int ret = 0;
    while(!sub.empty()) {
        ret += sub.top();
        sub.pop();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.assign(n, 0);
    for(auto &x: v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << solve(0, (int)v.size()-1, k);
}
