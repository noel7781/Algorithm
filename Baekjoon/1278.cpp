#include <bits/stdc++.h>
using namespace std;
int N;
int ret;
// vector<int> ans;
bool is_visit[1<<19];
int ans[131075];
int ans_last = 0;
bool is_done = false;
int solve(int acc, int depth) {
    if(depth == ret) {
        // ans.push_back(N);
        // for(auto it: ans) cout << it << "\n";
        ans[ans_last++] = N;
        for(int i = 0; i < ans_last; i++) {
            cout << ans[i] << "\n";
        }
        is_done = 1;
        return 1;
    }
    for(int i = 0; i < N; i++) {
        if(is_done) return 0;
        if(!is_visit[acc | (1 << i)]) {
            is_visit[acc | (1 << i)] = 1;
            ans[ans_last++] = i+1;
            // ans.push_back(i+1);
            if(!solve(acc | (1 << i), depth+1)) {
                ans_last--;
                // ans.pop_back();
            }
            is_visit[acc | (1 << i)] = 0;
        } else if(!is_visit[acc & ~(1 << i)]) {
            is_visit[acc & ~(1 << i)] = 1;
            // ans.push_back(i+1);
            ans[ans_last++] = i+1;
            if(!solve(acc & ~(1 << i), depth+1)) {
                ans_last--;
                // ans.pop_back();
            }
            is_visit[acc & ~(1 << i)] = 0;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    is_visit[0] = 1;
    ret = (1 << N) - 1;
    cout << ret << "\n";
    solve(0, 0);
}