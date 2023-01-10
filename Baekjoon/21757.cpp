#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> V;
int psum[100002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N+1); 
    vector<int> one, two, three;
    for(int i = 1; i <= N; i++) {
        cin >> V[i];
        psum[i] = psum[i-1] + V[i];
    }
    int total = psum[N];
    if(total % 4) {
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 1; i < N; i++) {
        if(psum[i] == total/4) one.push_back(i);
        if(psum[i] == total*2/4) two.push_back(i);
        if(psum[i] == total*3/4) three.push_back(i);
    }
    ll ret = 0;
    for(auto &f: one) {
        for(auto s = upper_bound(two.begin(), two.end(), f); s != two.end(); s++) {
            ret += three.end() - upper_bound(three.begin(), three.end(), *s);
        }

    }

    cout << ret << "\n";
}