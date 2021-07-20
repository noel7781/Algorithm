#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<pii> c_m;
int cache[10001][101];

int solve(int canPay, int pos) {
	if(canPay < 0) return 1e9;
	if(pos < 0) return 0;
	int& ret = cache[canPay][pos];
	if(ret != -1) return ret;
	ret = 1e9;
	
	ret = solve(canPay, pos-1);
	if(c_m[pos].first <= canPay) {
		ret = max(ret, c_m[pos].second + solve(canPay-c_m[pos].first, pos-1));
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	c_m.assign(n, pii());
	for(int i = 0; i < n; ++i) {
		cin >> c_m[i].second;	
	}
	for(int i = 0; i < n; ++i) {
		cin >> c_m[i].first;
	}
	for(int i = 0; i <= 10000; ++i) {
		for(int j = 0; j < n; ++j)
			if(solve(i, j) >= m) {
				cout << i << "\n";
				return 0;
			}
	}
}
