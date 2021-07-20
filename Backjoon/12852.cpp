#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n;
// cnt, before
pii cache[1000001];
void solve() {
    queue<pair<int, pii> > q;
    q.push(make_pair(0, make_pair(n, n)));
    cache[n] = make_pair(0, 0);
    while(!q.empty()) {
        int cnt = q.front().first, now =q.front().second.first, before = q.front().second.second;
        if(cache[now].first > cnt) {
            cache[now].first = cnt;
            cache[now].second = before;
        }
        if(now == 1) break;
        q.pop();
        if(now % 3 == 0) q.push(make_pair(cnt+1, make_pair(now/3, now)));
        if(now % 2 == 0) q.push(make_pair(cnt+1, make_pair(now/2, now)));
        q.push(make_pair(cnt+1, make_pair(now-1, now)));
    }
    cout << cache[1].first << "\n";
    int start = 1;
    vector<int> res;
    while(1) {
        res.push_back(start);
        int before = cache[start].second;
        if(start == n) break;
        start = before;
    }
    for(auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << " ";
    }
}

int main() {
    for(int i = 0; i <= 1000000; ++i) {
        cache[i] = make_pair(1e9, 0);
    }
    cin >> n;
    solve();
}