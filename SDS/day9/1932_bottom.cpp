#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[501][501];
int dp[501][501];
int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0] = arr[0][0];
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0) dp[i][j] = dp[i-1][j] + arr[i][j];
			else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
		}
	}
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		ret = max(ret, dp[n-1][i]);
	}
	printf("%d\n", ret);
}
