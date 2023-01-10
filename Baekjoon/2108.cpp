#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }        
    sort(v.begin(), v.end());
    int sum = 0;
    for(auto x: v) {
        sum += x;
    }
    int avg = 0;
    if(sum >= 0)
        avg = (int)((double)sum/n + 0.5);
    else
        avg = (int)((double)sum/n - 0.5);
    int mid = v[n/2];
    vector<int> cnt(8002), idx(8002);
    for(int i = 0; i < n; ++i) {
        cnt[v[i]+4000]++;
        idx[v[i]+4000] = i;
    }
    int maximum = 0;
    int max_idx = -1;
    for(int i = 0; i < n; ++i) {
        if(cnt[v[i]+4000] > maximum) {
            maximum = cnt[v[i]+4000];
            max_idx = idx[v[i]+4000];
        }
    }
    int most = -1;
    int count = 0;
    for(int i = 0; i < cnt.size(); ++i) {
        if(cnt[i] == maximum) {
            count += 1;
            most = i - 4000;
        }
        if(count == 2) break;
    }
    cout << avg << "\n";
    cout << mid << "\n";
    cout << most << "\n";
    cout << v[n-1] - v[0] << "\n";
}