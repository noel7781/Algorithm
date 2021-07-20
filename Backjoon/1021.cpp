#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> v;

int solve() {
    vector<bool> visit(n, 0);
    int ret = 0;
    int now = 0;
    int size = n;
    for(int i = 0; i < m; ++i) {
        int cnt = 0;
        int next = now;
        while(1) {
            if(visit[next]) {
                next += 1;
                if(next == n) next = 0;
                continue;
            }
            if(next == v[i]) break;
            cnt += 1;
            next += 1;
            if(next == n) next = 0;
        }
        visit[next] = 1;
        ret += min(size - cnt, cnt);
        size -= 1;
        if(i == n-1) break;
        while(1) {
            if(visit[next]) {
                next++;
                if(next == n) next = 0;
            }
            else break;
        }
        now = next;
    }
    
    return ret;
}

int main() {
    cin >> n >> m;
    v.assign(m, 0);
    for(int i = 0; i < m; ++i) {
        cin >> v[i];
        v[i] -= 1;
    }
    int ret = solve();
    cout << ret << "\n";
}
