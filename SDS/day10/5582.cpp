#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[4002][4002];
string s1, s2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2;
	int ans = 0;
	for(int i = 0; i < s1.length(); ++i) {
		for(int j = 0; j < s2.length(); ++j) {
			if(s1[i] == s2[j]) {
				if(i == 0 || j == 0) dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j-1]+1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans << "\n";
}
