#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

int n;
int max_v = 500010;

struct segTree {
    int n;
    vector<ll> count;
    segTree(int size) {
        n = size;
        count.resize(n*4, 0);
    }

    ll query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(nodeRight < left || right < nodeLeft) return 0;
        if(left <= nodeLeft && nodeRight <= right) return count[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right ,nodeLeft, mid, node*2) + query(left, right, mid+1, nodeRight, node*2+1);
    }

    ll query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }

    ll update(int index, int newValue, int nodeLeft, int nodeRight, int node) {
        if(index < nodeLeft || nodeRight < index) return count[node];
        if(nodeLeft == nodeRight) return count[node] += newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return count[node] = update(index, newValue, nodeLeft, mid, node*2) +
                             update(index, newValue, mid+1, nodeRight, node*2+1);
    }

    ll update(int index, int newValue) {
        return update(index, newValue, 0, n-1, 1);
    }
};

int comp(pii p1, pii p2) {
    if(p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
    //return p1.second < p2.second;
}

int main() {
    scanf("%d", &n);
    vector<pii> v(n, pii(0, 0));
    int map_idx = 0;

    segTree t(max_v+1);
    ll ret = 0;
    for(int i = 0; i < n; ++i) {
        v[i].first = i;
        scanf("%d", &v[i].second);
    }
    sort(v.begin(), v.end(), comp);
    int before = v[0].second;
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            v[i].second = ++map_idx;
        } else {
            if(before == v[i].second) {
                v[i].second = map_idx;
            } else {
                before = v[i].second;
                v[i].second = ++map_idx;
            }
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i) {
        ll num = v[i].second;
        ret += i - t.query(0, num);
        t.update(num, 1);
    }
    printf("%lld\n", ret);
}
