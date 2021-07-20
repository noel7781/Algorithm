#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N;
vector<int> v;
int cache[502][502];
int psum[502];

void calc_psum() {
    psum[0] = 0;
    for(int i = 1; i <= N; ++i) {
        psum[i] = psum[i-1] + v[i];
    }
}
int solve(int left, int right) {
    if(right == left) return 0;
    if(right - left == 1) return v[left] + v[right];
    int& ret = cache[left][right];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = left; i <= right; ++i) {
        ret = min(ret, solve(left, i) + solve(i+1, right) + psum[i] - psum[left-1] + psum[right] - psum[i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        memset(cache, -1, sizeof(cache));
        memset(psum, 0, sizeof(psum));
        cin >> N;
        v.assign(N+1, 0);
        for(int i = 1; i <= N; ++i) {
            cin >> v[i];
        }
        calc_psum();
        cout << solve(1, N) << "\n";
    }
}