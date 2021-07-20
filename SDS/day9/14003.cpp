#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> v;
int mapping[2000005];

int comp(pii a, pii b) {
	return a.second < b.second;
}


int main() {
	freopen("test.txt", "r", stdin);
	cin >> n;
	v.assign(n, pii());
	for(int i = 0; i < n; ++i) {
		v[i].first = i; cin >> v[i].second;
	}
	sort(v.begin(), v.end(), comp);
	int before = 1e9;
	int count = 1;
	for(int i = 0; i < n; ++i) {
		if(before == v[i].second) {
			if(i != 0) {
				v[i].second = v[i-1].second;
				continue;
			}
		}
		before = v[i].second;
		v[i].second += 1000000000;
		mapping[count] = v[i].second;
		v[i].second = count;
		count++;
	}
	sort(v.begin(), v.end());
//	for(int i = 0; i < n; ++i) {
//		printf("v[%d].second: %d, mapping val: %d\n", i, v[i].second, mapping[v[i].second]);
//	}
	
}
