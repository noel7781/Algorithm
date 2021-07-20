#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define INF 1e9

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;
int sta, fin;
int cache[1501][1501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cache[i][j] = (i == j ? 0 : INF);
            }
        }
        for(int i = 0; i < m; ++i){
            int f, t; cin >> f >> t;
            f--; t--;
            // f와 t를 잇는 경우
            for(int j = 0; j < n; ++j) {
                int c1 = min(cache[j][f]+1, cache[j][t]);
                int c2 = min(cache[j][t]+1, cache[j][f]);
                cache[j][f] = c1;
                cache[j][t] = c2;
            }
        }
        int ret = 0;
        for(int i = 0; i < k; ++i) {
            cin >> sta >> fin;
            sta--; fin--;
            int ans = (cache[sta][fin] < INF ? cache[sta][fin] : -1);
            ret += ans;
        }
        cout << "Case #" << i+1 << "\n";
        cout << ret << "\n";
    }
}
