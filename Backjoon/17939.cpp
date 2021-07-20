#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[100005];
vector<int> coins;
int coin_sum[100005];
int N;

void pre_sum() {
    coin_sum[0] = coins[0];
    for(int i = 1; i < N; ++i) {
        coin_sum[i] = coin_sum[i-1] + coins[i];
    }
    return;
}

// int solve(int pos) {
//     int& ret = cache[pos];
//     if(ret != -1)
//         return ret;
//     ret = 0;
//     for(int i = pos + 1; i < N; ++i) {
//         int sum = 0;
//         if(pos == 0)
//             sum = coin_sum[i - 1];
//         else
//             sum = coin_sum[i - 1] - coin_sum[pos - 1];
//         ret = max(ret, (i - pos) * coins[i] - sum + solve(i + 1));
//     }
//     return ret;
// }

int solve(int pos) {
    int ret = 0;
    int max_val = -1;
    int max_idx = -1;
    for(int i = max_idx + 1; i < N; ++i) {
        max_val = -1;
        for(int j = i; j < N; ++j) {
            if(coins[j] > max_val) {
                max_val = coins[j];
                max_idx = j;
            }
        }
        if(i != 0)
            ret = max(ret, ret + max_val * (max_idx - i) - coin_sum[max_idx - 1] + coin_sum[i - 1]);
        else
            ret = max(ret, ret + max_val * (max_idx - i) - coin_sum[max_idx - 1]);
        i = max_idx;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int p; cin >> p;
        coins.push_back(p);
    }
    pre_sum();
    cout << solve(0) << "\n";
}
