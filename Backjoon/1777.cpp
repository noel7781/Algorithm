#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> inv;
vector<int> v;

struct segTree {
    int n;
    vector<int> count;
    segTree(vector<int>& ones) {
        n = ones.size();
        count.resize(4*n);
        init(ones, 0, n-1, 1);
    }
    int init(vector<int>& ones, int left, int right, int node) {
        if(left == right) {
            return count[node] = ones[left];
        }
        int mid = (left + right) >> 1;
        int l = init(ones, left, mid, node*2);
        int r = init(ones, mid+1, right, node*2+1);
        return count[node] = l + r;
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(nodeLeft > right || nodeRight < left) return 0;
        if(left <= nodeLeft && nodeRight <= right) return count[node];
        int mid = (nodeLeft + nodeRight) >> 1;
        int l = query(left, right, nodeLeft, mid, node*2);
        int r = query(left, right, mid+1, nodeRight, node*2+1);
        return l+r;

    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
    int update(int index, int nodeLeft, int nodeRight, int node) {
        if(index < nodeLeft || nodeRight < index) return count[node];
        if(nodeLeft == nodeRight) {
            return count[node] = 0;
        }
        int mid = (nodeLeft + nodeRight) >> 1;
        return count[node] = update(index, nodeLeft, mid, node*2) + 
                             update(index, mid+1, nodeRight, node*2+1);
        
    }
    int update(int index) {
        return update(index, 0, n-1, 1);
    }
};

int Kth(segTree& t, int cnt) {
    int lo = 0, hi = N+1;
    while(lo+1 < hi) {
        int mid = (lo + hi) >> 1;
        if(t.query(mid, N) <= cnt+1) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    inv.resize(N);
    v.assign(N, 0);
    for(auto &it: inv) cin >> it;
    vector<int> ones(N+1, 1);
    segTree t(ones);
    for(int i = N-1; i >= 0; i--) {
        int pos = Kth(t, inv[i]);
        t.update(pos);
        v[pos] = i+1;
    }
    for(auto x: v) {
        cout << x << " ";
    }
    return 0;
}