#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
int board[1001][1001];
int dp[1001][1001];
int ret = 0;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%1d", &board[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(board[i][j] == 0) dp[i][j] = 0;
			else {
//				if(board[i][j] == 1) dp[i][j] = 1;
//				ret = max(ret, dp[i][j]);
				if(board[i-1][j] == 0 || board[i][j-1] == 0 || board[i-1][j-1] == 0) {
					dp[i][j] = 1;
					ret = max(ret, dp[i][j]);
				} else {
					int sz = sqrt(min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]));
						sz += 1;
						dp[i][j] = sz * sz;
						ret = max(ret, dp[i][j]);
			
				}
			}
		}
	}
	printf("%d\n", ret);
}
