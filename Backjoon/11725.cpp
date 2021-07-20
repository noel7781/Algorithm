#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N;
int cnt = 0;
vector<vi> v;
vi p;
vector<bool> chosen;

void solve(int idx) {
    if(cnt == N-1) return;
    chosen[idx] = true;
    for(int j = 0; j < v[idx].size(); ++j) {
        if(chosen[v[idx][j]]) continue;
        p[v[idx][j]] = idx;
        chosen[v[idx][j]] = true;
        cnt += 1;
        solve(v[idx][j]);
    }
}

int main() {
    cin >> N;
    v.resize(N+1);
    p.resize(N+1);
    chosen.resize(N+1);
    for(int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1);
    for(int i = 2; i <= N; ++i) {
        cout << p[i] << "\n";
    }
}