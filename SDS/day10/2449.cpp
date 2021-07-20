#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, k;
vector<int> v;

int cache[201][201];

int solve(int left, int right) {
	if(left == right) return 0;
	int& ret = cache[left][right];
	if(ret != -1) return ret;
	ret = 1e9;
	for(int mid = left; mid < right; ++mid) {
		int l = solve(left, mid);
		int r = solve(mid+1,right);
		int w = 1;
		if(v[left] == v[mid+1]) w = 0;
		ret = min(ret, l + r + w);	
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	v.assign(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int ret = solve(0, n-1);
	cout << ret << "\n";
}
