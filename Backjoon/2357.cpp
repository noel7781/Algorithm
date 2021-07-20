#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

#define INF 1234567890

struct segtree {
    int n;
    // pair<Min, Max> 
    vector<pair<int, int> > rangeMinMax;
    segtree(const vector<int>& array) {
        n = array.size();
        rangeMinMax.resize(4*n);
        init(array, 0, n-1, 1);
    }
    pii init(const vector<int>& array, int left, int right, int node) {
        if(left == right) {
            rangeMinMax[node].first = rangeMinMax[node].second = array[left];
            return rangeMinMax[node];
        }
        int mid = (left + right) / 2;
        pii leftMinMax = init(array, left, mid, node*2);
        pii rightMinMax = init(array, mid+1, right, node*2 + 1);
        rangeMinMax[node].first = min(leftMinMax.first, rightMinMax.first);
        rangeMinMax[node].second = max(leftMinMax.second, rightMinMax.second);
        return rangeMinMax[node];
    }
    pii query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return make_pair(INF, -INF);
        if(left <= nodeLeft && nodeRight <= right) {
            return rangeMinMax[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        pii c1 = query(left, right, node*2, nodeLeft, mid);
        pii c2 = query(left, right, node*2 + 1, mid+1, nodeRight);
        return make_pair(min(c1.first, c2.first), max(c1.second, c2.second));
    }
    pii query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    while(T--) {
        int size; int q;
        cin >> size >> q;
        vector<int> array(size);
        for(int i = 0; i < size; ++i) {
            cin >> array[i];
        }
        struct segtree t(array);
        while(q--) {
            int a, b; cin >> a >> b;
            pii ret = t.query(a-1,b-1);
            cout << ret.first << " " << ret.second <<"\n";
        }
    }
}
