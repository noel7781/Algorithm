#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> V;
int psum[100005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; V.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
        psum[i+1] = psum[i] + V[i];
    }
    cin >> M;
    while(M--) {
        int p, q; cin >> p >> q;
        cout << psum[q] - psum[p-1] << "\n";
    }
}