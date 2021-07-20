#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> visit;
vector<int> done;

void dfs(int now, int& ret) {
    visit[now] = 1;
    int next = v[now];
    if(!visit[next]) {
        dfs(next, ret);
    }
    // 이미 방문했지만 끝난 노드가 아니면 사이클이다.
    else if(!done[next]) {
        // 팀원을 세는과정
        for(int i = next; i != now; i = v[i]) {
            ret++;
        }
        // 자기자신
        ret++;
    }
    done[now] = 1;
}

int solve() {
    int ret = 0;
    visit = vector<int>(n+1, 0);
    done = vector<int>(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        if(!visit[i]) {
            dfs(i, ret);
        } 
    }
    return ret;
}
int main() {
    int t; cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        v.assign(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        int ret = solve();
        cout << n - ret << "\n";

    }
}
