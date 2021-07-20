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
    vector<int> accSum(h+1, 0);
    for(int i = 0; i < n; ++i) {
        int k; cin >> k;
        if(i & 1) {
            accSum[h-k+1]++;
        } else {
            accSum[1]++;
            accSum[k+1]--;
        }
    }
    int ret = 1e9, count = 0;
    for(int i = 1; i <= h; ++i) {
        accSum[i] += accSum[i-1];
        if(accSum[i] < ret) {
            ret = accSum[i];
            count = 1;
        } else if(accSum[i] == ret) {
            count += 1;
        }
    }
    cout << ret << " " << count << "\n";
}