#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, string> pis;

int n;

bool comp(pis a, pis b) {
    if(a.first.first < b.first.first) return 1;
    else if(a.first.first == b.first.first) {
        return a.first.second < b.first.second;
    } else {
        return 0;
    }
}

int main() {
    cin >> n;
    vector<pis> v;
    v.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first.first >> v[i].second;
        v[i].first.second = i;
    }
    sort(v.begin(), v.end(), comp);
    for(auto x: v) {
        cout << x.first.first << " " << x.second << "\n";
    }
}