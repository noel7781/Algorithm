#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> places;
int dist(pii& A, pii& B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >>t;
    while(t--) {
        cin >> N;
        places.resize(N+2);
        for(int i = 0; i < N+2; i++) {
            cin >> places[i].first >> places[i].second;
        }
        vector<int> is_visit(N+2, 0);
        is_visit[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int pos = q.front(); q.pop();
            for(int i = 0; i < N+2; i++) {
                if(!is_visit[i] && dist(places[pos], places[i]) <= 1000) {
                    is_visit[i] = 1;
                    q.push(i);
                }
            }
        }
        if(is_visit[N+1]) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }


    }
}