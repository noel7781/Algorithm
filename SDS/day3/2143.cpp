#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int target;
int n, m;
vector<int> v1, v2;

int main() {
    cin >> target;
    cin >> n; v1.assign(n, 0);
    for(auto &it: v1) {
        cin >> it;
    }
    cin >> m; v2.assign(m, 0);
    for(auto &it: v2) {
        cin >> it;
    }
    vector<int> sum1, sum2;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = i; j < n; ++j) {
            sum += v1[j];
            sum1.push_back(sum);
        }
    }
    for(int i = 0; i < m; ++i) {
        int sum = 0;
        for(int j = i; j < m; ++j) {
            sum += v2[j];
            sum2.push_back(sum);
        }
    }
    sort(sum2.begin(), sum2.end());
    ll ret = 0;
    for(int i = 0; i < sum1.size(); ++i) {
        auto it_l = lower_bound(sum2.begin(), sum2.end(), target-sum1[i]);
        auto it_u = upper_bound(sum2.begin(), sum2.end(), target-sum1[i]);
        ret += (ll)(it_u - it_l);
    }
    cout << ret << "\n";
}