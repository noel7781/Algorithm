#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> V;

struct segTree {
    int n; vector<int> range_min_idxs;
    segTree(vector<ll>& v) {
        n = v.size();
        range_min_idxs = vector<int>(4*n, -1);
        build(1, 0, n-1, v);
    }
    int build(int node, int left, int right, vector<ll>& v) {
        if(left == right) {
            return range_min_idxs[node] = left;
        }
        int mid = (left+right)/2;
        int left_min = build(2*node, left, mid, v);
        int right_min = build(2*node+1, mid+1, right, v);
        if(v[left_min] <= v[right_min]) {
            return range_min_idxs[node] = left_min;
        } else {
            return range_min_idxs[node] = right_min;
        }
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(left > nodeRight || right < nodeLeft) return -1;
        if(left <= nodeLeft && nodeRight <= right) return range_min_idxs[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        int left_min = query(left, right, nodeLeft, mid, 2*node);
        int right_min = query(left, right, mid+1, nodeRight, 2*node+1);
        if(left_min == -1) return right_min;
        if(right_min == -1) return left_min;
        return V[left_min] <= V[right_min] ? left_min : right_min;
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
};

ll solve(segTree& t, vector<ll>& V, int left, int right) {
    if(left == right) return V[left];
    int min_idx = t.query(left, right);
    ll ret = V[min_idx] * (right - left + 1);
    if(min_idx-1 >= left)
        ret = max(ret, solve(t, V, left, min_idx-1));
    if(min_idx+1 <= right) 
        ret = max(ret, solve(t, V, min_idx+1, right));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    V.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }
    segTree t(V);

    ll ret = solve(t, V, 0, N-1);
    cout << ret << "\n";
}