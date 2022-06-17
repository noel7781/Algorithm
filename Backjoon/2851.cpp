#include <bits/stdc++.h>
using namespace std;
vector<int> V(10);
int main() {
    for(auto &it: V) cin >> it;
    int ret = -1, sum = 0;
    int l = 0, r = 0;
    while(r <= 10) {
        if(abs(100 - sum) < abs(100 - ret)) {
            ret = sum;
        } else if(abs(100 - sum) == abs(100 - ret)) {
            ret = max(ret, sum);
        }
        if(sum > 100) {
            break;
        } else if(sum == 100) {
            break;
        } else {
            sum += V[r++];
        }
    }
    cout << ret << "\n";
}