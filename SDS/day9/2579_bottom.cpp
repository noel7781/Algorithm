#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[301][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> v(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	dp[0][0] = v[0];
	dp[1][0] = v[1];
	
	// 새로운 계단을 밟는 경우 dp[i][0]
	// 연속된 2개의 계단을 밟는 경우 dp[i][1] 
	for(int i = 2; i <= n; ++i) {
		for(int j = 0;	 j < 2; ++j) {
			if(j == 0) dp[i][j] = max(dp[i-2][0], dp[i-2][1]) + v[i];
			if(j == 1) dp[i][j] = dp[i-1][0] + v[i];
		}
	}
	
//	for(int i =1; i <= n; ++i) {
//		for(int j = 0; j < 2; ++j) {
//			printf("dp[%d][%d] : %d\n", i, j, dp[i][j]);
//		}
//	}
//	
	int ret = 0;
	for(int i = 0; i < 2; ++i) {
		ret = max(ret, dp[n][i]);
	}
	cout << ret << "\n";
	
}
