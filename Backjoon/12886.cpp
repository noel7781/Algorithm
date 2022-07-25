#include <bits/stdc++.h>
using namespace std;

bitset<1003003001> bs;

int check(vector<int>& v) {
    int sum = 0;
    int acc = 1;
    for(int i = 0; i < 3; i++) {
        sum += v[i] * acc;
        acc *= 501;
    }
    return sum;
}

int search(vector<int> v) {
    if(v[0] == v[1] && v[1] == v[2]) return 1;
    sort(v.begin(), v.end());
    int curr = check(v);
    if(bs.test(curr)) return 0;
    int ret = 0;
    bs.set(curr, true);
    int sm = v[0];
    int md = v[1];
    v[0] += sm; v[1] -= sm;
    ret |= search(v);
    v[1] += sm; v[2] -= sm;
    ret |= search(v);
    v[0] -= sm; v[2] += sm;
    v[1] += md; v[2] -= md;
    ret |= search(v);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> V(3);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    int ret = search(V); 
    cout << ret << "\n";
}