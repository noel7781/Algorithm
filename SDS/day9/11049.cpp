#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> v;
int cache[501][501];

int solve(int l, int r) {
	if(l == r) return 0;
	if(r - l == 1) {
		return v[l].first * v[l].second * v[r].second;
	}
	int& ret = cache[l][r];
	if(ret != -1) return ret;
	ret = 1e9;
	for(int k = l; k < r; ++k) {
		ret = min(ret, solve(l, k) + solve(k+1, r) + v[l].first * v[k].second * v[r].second);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	int ret = 1e9;
	ret = solve(0, n-1);
	cout << ret << "\n";
}
