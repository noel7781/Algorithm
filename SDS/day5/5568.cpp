#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int n, k;
set<int> s;
vector<string> v;
int ans = 0;

void solve(string& ret, vector<bool>& visit, int cnt) {
    if(cnt == k) {
        int num = stoi(ret);
        if(s.find(num) == s.end()) {
            s.insert(num);
            ans += 1;
        }
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(visit[i]) continue;
        visit[i] = 1;
        ret += v[i];
        solve(ret, visit, cnt+1);
        visit[i] = 0;
        ret = ret.substr(0, ret.size() - v[i].size());
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.assign(n, "");
    for(auto &it: v) cin >> it;
    vector<bool> visit(n, 0);
    string ret = "";
    solve(ret, visit, 0);
    cout << ans << "\n";
}