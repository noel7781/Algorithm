#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int dp[10001][101];
pii c_m[101];
int n, m;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> c_m[i].second;
	}
	for(int i = 0; i < n; ++i) {
		cin >> c_m[i].first;
	}
	sort(c_m, c_m+n);


	for(int i = 0; i <= 10000; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i - c_m[j].first >= 0 && j > 0)
				dp[i][j] = max(dp[i][j-1], max(dp[i][j], dp[i-c_m[j].first][j-1] + c_m[j].second));
			else if(i - c_m[j].first >= 0 && j == 0) {
				dp[i][j] = max(dp[i][j-1], max(dp[i][j], c_m[j].second));
			}
			else {
				dp[i][j] = max(dp[i][j], dp[i][j-1]);
			}
		}
	}
	for(int i = 0; i <= 10000; ++i) {
		for(int j = 0; j < n; ++j) {
			if(dp[i][j] >= m) {
				cout << i << "\n";
				return 0;
			}
		}	
	}
}
