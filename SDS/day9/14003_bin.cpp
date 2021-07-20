#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
vector<int> v;
int d[1000001];
int p[1000001];
int idx_record[1000001];

int main() {
	cin >> n;
	v.assign(n+1, 0);
	for(int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	int idx = 1;
	vector<int> arr;
	for(int i = 1; i <= n; ++i) {
		auto it = lower_bound(arr.begin(), arr.end(), v[i]);
		if(it == arr.end()) {
			arr.push_back(v[i]);
			idx_record[i] = idx;
			idx++;
		}
		else {
			idx_record[i] = it - arr.begin() + 1;
			*it = v[i];
		}
	}
	int ans = arr.size();
	int tmp = ans;
	vector<int> ret;
	for(int i = n; i >= 1; --i) {
		if(idx_record[i] == tmp) {
			tmp--;
			ret.push_back(v[i]);
		}
		if(tmp == 0) break;
	}
	cout << ans << "\n";
	for(auto it = ret.rbegin(); it != ret.rend(); ++it) {
		cout << *it << " ";
	}

	cout << "\n";
}
