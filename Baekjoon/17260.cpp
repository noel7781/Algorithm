#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> H;
vector<int> is_visit;
vector<vector<int> > adj;
int is_end = 0;

void spread(int src, int thr) {
    if(src == K) {
        for(auto next: adj[src]) {
            if(!is_visit[next]) {
                is_visit[next] = 1;
                spread(next, H[src]);
            }
        }
    } else {
        if(H[src] >= thr) {
            is_end = 1;
            return;
        }
        for(auto next: adj[src]) {
            if(!is_visit[next]) {
                if(is_end) return;
                is_visit[next] = 1;
                spread(next, min(2*thr - H[src], 2000012));
            }
        }
    }
    return;
}

int main() {
    cin >> N >> K;
    H.resize(N);
    is_visit.assign(N, 0);
    for(auto &it: H) cin >> it;
    adj.resize(N);
    K -= 1;
    for(int i = 0; i < N-1; i++) {
        int A, B; cin >> A >> B;
        A -= 1; B -= 1;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    is_visit[K] = 1;
    spread(K, H[K]);
    if(is_end) cout << 1 << "\n";
    else cout << 0 << "\n";
}