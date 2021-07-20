#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
vector<pii> wv;
int dp[100001][101];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	wv.assign(n, pii());
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &wv[i].first, &wv[i].second);
	}
	for(int w = 0; w <= k; ++w) {
		for(int i = 0; i < n; ++i) {
			if(w == 0) dp[w][i] = 0;
			else {
				if(wv[i].first <= w) {
					dp[w][i] = max(wv[i].second + dp[w-wv[i].first][i-1], dp[w][i]);
				}
				dp[w][i] = max(dp[w][i], dp[w][i-1]);
			}
		}
	}
	printf("%d\n", dp[k][n-1]);
}

