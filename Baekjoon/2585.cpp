#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

int N, K;
vector<pii> v;
bool chosen[1010];

int main() {
    scanf("%d %d", &N, &K);
    v.assign(N+2, make_pair(0, 0));    
    for(int i = 1; i <= N; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    v[N+1] = make_pair(10000, 10000);
    int lo = 1, hi = 15000;
    int mid = (lo + hi) / 2;
    while(lo <= hi) {
        memset(chosen, 0, sizeof(chosen));
        mid = (lo + hi) / 2;
        // (idx, count)
        queue<pii> q;
        q.push(make_pair(0, 0));
        chosen[0] = 1;
        bool fail = 0;
        while(!q.empty()) {
            int now = q.front().first, cnt = q.front().second;
            q.pop();
            if(now == N+1) {
                fail = 1;
                break;
            }
            if(cnt == K+1) {
                continue;
            }
            for(int i = 1; i <= N+1; ++i) {
                if(!chosen[i] && mid*mid > (v[now].first - v[i].first)*(v[now].first - v[i].first) + (v[now].second - v[i].second)*(v[now].second - v[i].second)) {
                    chosen[i] = 1;
                    q.push(make_pair(i, cnt+1));
                }
            }
        }
        if(fail) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", lo / 10+!(!(lo%10)));
}