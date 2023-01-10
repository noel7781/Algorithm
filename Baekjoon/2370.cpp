#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> V;
vector<int> total;

int find_index(int x) {
    return lower_bound(total.begin(), total.end(), x) - total.begin();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int p1, p2; cin >> p1 >> p2;
        V.push_back({p1, p2});
        total.push_back(p1);
        total.push_back(p2);
    }
    sort(total.begin(), total.end());
    total.erase(unique(total.begin(), total.end()), total.end());
    int size = total.size();
    vector<int> v(size);
    vector<int> ans(N+1);
    for(int i = 0; i < N; i++) {
        int p1 = find_index(V[i].first);
        int p2 = find_index(V[i].second);
        for(int j = p1; j <= p2; j++) {
            v[j] = i+1;
        }
    }
    int ret = 0;
    for(int i = 0; i < size; i++) {
        if(v[i] == 0) {
            continue;
        }
        ans[v[i]]++;
        if(ans[v[i]] == 1) {
            ret++;
        }
    }
    cout << ret << "\n";
}