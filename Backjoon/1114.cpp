#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int L, K, C;
vector<int> points;
map<int, int> m;

vector<int> permutation;
vector<int> chosen;


int search() {
    printf("permuation size %d\n", permutation.size());
	if(permutation.size() == C) {
		// 순열 처리
        printf("C: %d perm[0] %d\n", C, permutation[0]);
        int ret = permutation[0];
        for(int i = 0; i < C-1; i++) {
            ret = max(ret, permutation[i+1]-permutation[i]);
        }
        ret = max(ret, L - permutation[C-1]);
        printf("Ret: %d\n", ret);
        return ret;
	} else {
        int ret = 1e9;
		for(int i = 0; i < K; ++i) {
			if(chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(points[i]);
            printf("push back %d\n", points[i]);
            int tmp = search();
            if(tmp <= ret) {
                ret = tmp;
                if(m.find(ret) == m.end())
                    m[ret] = permutation[0];
                else
                    m[ret] = min(m[ret], permutation[0]);
            } 
			chosen[i] = false;
			permutation.pop_back();
		}
        return ret;
	}
}


int check(int thr) {
    vector<int> pick;
    int maxDist = search();
    return maxDist >= thr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> K >> C;
    points.resize(K);
    chosen.resize(K);
    for(auto &it: points) cin >> it;
    sort(points.begin(), points.end());
    int lo = 0, hi = 1e9+1;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo <<  " " << m[lo] << "\n";
}
