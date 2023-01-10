#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> houses;
vector<pii> chickens;

int chicken_distance(pii A, pii B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}

int search(int pos, vector<pii>& subset) {
    if(subset.size() > m) return 1e9;
    if(pos >= chickens.size()) {
        if(subset.size() > 0) {
            int ret = 0;
            for(int i = 0; i < houses.size(); ++i) {
                int tmp = 1e9;
                for(int j = 0; j < subset.size(); ++j) {
                    tmp = min(tmp, chicken_distance(houses[i], subset[j]));
                }
                ret += tmp;
            }
            return ret;
        } else {
            return 1e9;
        }
    }
    int ret = 1e9;
    subset.push_back(chickens[pos]);
    ret = min(ret, search(pos+1, subset));
    subset.pop_back();
    ret = min(ret, search(pos+1, subset));
    return ret;
}

int solve(vector<vector<int> >& city) {
    int ret = 0;
    vector<pii> subset;
    ret = search(0, subset);
    return ret;
}

int main() {
    cin >> n >> m;
    vector<vector<int> > city(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> city[i][j];
            if(city[i][j] == 1) houses.push_back(make_pair(i, j));
            else if(city[i][j] == 2) chickens.push_back(make_pair(i, j));
        }
    }
    cout << solve(city) << "\n";
}
