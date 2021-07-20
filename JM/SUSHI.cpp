#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, budget;
int cost[21];
int pref[21];
int cache[21][6000000];

int solve(int item, int budget) {
    printf("item %d budget %d\n", item, budget);
    if(item == n)
        return 0;
    int& ret = cache[item][budget];
    if(ret != -1) return ret;
    ret = 0;
    ret = solve(item+1, budget);
    if(budget >= cost[item]) {
        ret = max(ret, pref[item] + solve(item, budget-cost[item]));
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> budget;
        budget /= 100;
        for(int i = 0; i < n; ++i) {
            cin >> cost[i] >> pref[i];
            cost[i] /= 100;
        }
        cout << solve(0, budget) << "\n";
    }
}
