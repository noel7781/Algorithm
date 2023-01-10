#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

int n, k;
ll blocks = 0;

ll dfs(vector<vector<int> >& adj, vector<ll>& v, vector<bool>& visit, ll limit, int pos) {
    priority_queue<ll> pq;
    visit[pos] = true;
    ll val = 0;
    ll sum = 0;
    for(int i = 0; i < adj[pos].size(); ++i) {
        int next = adj[pos][i];
        if(!visit[next]) {
            val = dfs(adj, v, visit, limit, next);
            sum += val;
            pq.push(val);
        }
    }
    while(!pq.empty() && sum + v[pos] > limit) {
        blocks++;
        sum -= pq.top();
        pq.pop();
    }
    return sum + v[pos];
}

bool check(vector<vector<int> >& adj, vector<ll>& v, vector<bool>& visit, ll limit) {
    int cnt = 0;
    visit[0] = true;
    blocks = 0;
    dfs(adj, v, visit, limit, 0);
    //cout << "limit: " << limit << " and cnt: " << blocks << endl;
    if(blocks <= k) {
        return true;
    }
    return false;
}

ll solve(vector<vector<int> >& adj, vector<ll>& v) {
    ll lo = 0;
    ll sum = 0;
    for(int i = 0; i < v.size(); ++i) {
        lo = max(lo, v[i]);
        sum += v[i];
    }
    ll hi = sum;
    //cout<<"lo: " << lo << " and hi:" << hi << endl;
    while(lo+1 < hi) {
        ll mid = (lo + hi) / 2;
        vector<bool> visit(n, 0);
        if(check(adj, v, visit, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    vector<bool> visit(n, 0);
    if(check(adj, v, visit, lo)) {
        return lo;
    }
    return hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t--) {
        blocks = 0;
        cin >> n >> k;
        vector<vector<int> > adj(n, vector<int>());
        vector<ll> v(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        for(int i = 0; i < n-1; ++i) {
            int a, b; cin >> a >> b;
            a -= 1; b -= 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << solve(adj, v) << endl;

    }
}
