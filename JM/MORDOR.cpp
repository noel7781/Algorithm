#include <iostream>
#include <vector>
#include <cstring>

#define INF 1e9

using namespace std;

struct segTree {
    int n;
    vector<int> rangeMin;
    vector<int> rangeMax;

    segTree(const vector<int>& arr) {
        n = arr.size();
        rangeMin.resize(n*4);
        rangeMax.resize(n*4);
        init(arr, 0, n-1, 1, 0);
        init(arr, 0, n-1, 1, 1);
    }

    int init(const vector<int>& arr, int left, int right, int node, int is_max) {
        if(left == right) {
            if(is_max)
                return rangeMax[node] = arr[left];
            return rangeMin[node] = arr[left];
        }
        int mid = (left + right) / 2;
        int leftValue = init(arr, left, mid, node*2, is_max);
        int rightValue = init(arr, mid+1, right, node*2+1, is_max);
        if(is_max) {
            return rangeMax[node] = max(leftValue, rightValue);
        }
        return rangeMin[node] = min(leftValue, rightValue);
    }


    int query(int left, int right, int nodeLeft, int nodeRight, int node, int is_max) {
        if(nodeLeft > right || nodeRight < left) {
            if(is_max) return -INF;
            else return INF;
        }
        if(left <= nodeLeft && nodeRight <= right) {
            if(is_max) return rangeMax[node];
            else return rangeMin[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        if(is_max) return max(
                query(left, right, nodeLeft, mid, node*2, is_max),
                query(left, right, mid+1, nodeRight, node*2+1, is_max)
                );
        else return min(
                query(left, right, nodeLeft, mid, node*2, is_max),
                query(left, right, mid+1, nodeRight, node*2+1, is_max)
                );
    }

    int query(int left, int right) {
        return query(left, right, 0, n-1, 1, 1) - query(left, right, 0, n-1, 1, 0);
    }
};

int n, q;
int from, to;

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> q;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        segTree t(v);
        for(int i = 0; i < q; ++i) {
            cin >> from >> to;
            cout << t.query(from, to) << "\n";
        }
    }
    return 0;
}
