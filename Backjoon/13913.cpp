#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, k;
int now[100001];
int pre[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(pre, -1, sizeof(pre));
    cin >> n >> k;
    queue<pair<pii, int> > q;
    q.push({{n,-1}, 0});
    vector<int> res;
    while(!q.empty()) {
        int pos = q.front().first.first, before = q.front().first.second, cnt = q.front().second;
        q.pop();
        if(pos < 0 || pos > 100000) continue;
        if(pre[pos] != -1) continue;
        pre[pos] = before;
        if(pos == k) {
            cout << cnt << "\n";
            int p = k;
            while(1) {
                res.push_back(p);
                if(p == n) break;
                p = pre[p];
            }
            break;
        }
        if(pos > 0) 
            q.push({{pos-1, pos}, cnt+1});
        if(pos <= 100000)
            q.push({{pos+1, pos}, cnt+1});
        if(pos <= 50000)
            q.push({{pos*2, pos}, cnt+1});
    }
    for(auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << " ";
    }
}