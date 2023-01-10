#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans_idx = 0, ans_sum = 0;
    for(int i = 0; i < 5; i++) {
        int tmp_sum = 0;
        for(int j = 0; j < 4; j++) {
            int x; cin >> x;
            tmp_sum += x;
        }
        if(ans_sum < tmp_sum) {
            ans_sum = tmp_sum; ans_idx = i+1;
        }
    }
    cout << ans_idx << " " << ans_sum << "\n";
}