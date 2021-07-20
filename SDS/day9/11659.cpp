#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int pSum[100001];
int n,m;

void calc_psum(vector<int>& v) {
    for(int i = 1; i <= n; ++i) {
        pSum[i] = pSum[i-1] + v[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> v(n+1, 0);
    for(int i =1 ; i <= n; ++i) {
        cin >> v[i];
    }
    calc_psum(v);
    while(m--) {
        int a, b; cin >> a >> b;
        cout << pSum[b] - pSum[a-1] << "\n";
    }
}