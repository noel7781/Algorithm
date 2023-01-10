#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;

int count(int lim) {
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        sum += v[i];
        if(sum >= lim) {
            cnt += 1;
            sum = 0;
        }
    }
    return cnt;
}

int solve() {
    int lo = 0, hi = 1e8;
    int mid = (lo + hi) / 2;
    int res = 0;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        int cnt = count(mid);
        if(cnt > K) {
            lo = mid + 1;
        } else if(cnt < K){
            hi = mid - 1;
        } else {
            res = max(res, mid);
            lo = mid + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    v.assign(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
    } 
    cout << solve() << "\n";
}