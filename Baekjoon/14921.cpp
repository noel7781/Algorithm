#include <bits/stdc++.h>
#define INF 200000001
using namespace std;
int N;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    int ret = INF;
    int l = 0, r = N-1;
    while(l < r) {
        int sum = V[l] + V[r];
        int abs_sum = abs(sum);
        if(abs_sum < abs(ret)) {
            ret = sum;
        }
        if(sum < 0) {
            l++;
        } else if(sum > 0) {
            r--;
        } else {
            break;
        }
    }
    cout << ret << "\n";
}