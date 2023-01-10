#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> drink;
int cache[10001][3];

int solve(int pos, int cont) {
    if(cont >= 3) return 0;
    if(pos >= n) return 0;
    int& ret = cache[pos][cont];
    if(ret != -1)
        return ret;
    ret = 0;

    if(cont < 2)
        ret = max(ret, drink[pos] + solve(pos+1, cont+1));
    ret = max(ret, solve(pos+1, 0));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    drink.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> drink[i];
    }
    cout << solve(0, 0) << "\n";

}
