#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> v;
int cache[1001][1001];
int solve(int left, int right) {
	if(right < left) return 0;
	if(left+1 == right) {
		return max(v[left], v[right]);
	} 
	if(left == right) return v[left];
	int& ret = cache[left][right];
	if(ret != -1) return ret;
	ret = v[left] + min(solve(left+2,right),solve(left+1,right-1));
	ret = max(ret, v[right] + min(solve(left,right-2),solve(left+1,right-1)));
	return ret;
}

int main() {
	int t; cin >> t;
	while(t--) {
		memset(cache, -1, sizeof(cache));
		v.clear();
		cin >> n;
		v.assign(n, 0);
		for(auto &it: v) cin >> it;
		cout << solve(0, n-1) << "\n";
	}
}
