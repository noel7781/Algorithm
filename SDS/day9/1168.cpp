#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define PIVOT (1<<17)

using namespace std;

int tree[PIVOT*2];
int n, k; 

void update(int i, int v) {
    i += PIVOT;
    tree[i] += v;
    while(i >>= 1) {
        tree[i] += v;
    }
}

int query(int l, int r) {
    l += PIVOT; r += PIVOT;
    int ret = 0;
    while(l <= r) {
        if(l % 2) ret += tree[l++];
        if(!(r % 2)) ret += tree[r--];
        l >>= 1; r >>= 1;
    }
    return ret;
}

int getNextNumber(int last, int total) {
    int lo = 0, hi = n;
    int find_count = k;
    int left = query(last+1, n);
    if(left < k) {
        find_count = k - left;
        last = 0;
    } 
    if(total < find_count) {
        find_count = find_count % total;
        if(find_count == 0) find_count = total;
    }
    if(total == 1) {
        find_count = 1;
    }

    while(lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if(query(last+1,mid) >= find_count) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        update(i+1, 1);
    }
    int cnt = 0;
    int last_del = -1;
    cout << "<";
    while(cnt < n-1) {
        int next_del = getNextNumber(last_del, n-cnt);
        update(next_del, -1);
        cout << next_del << ", ";
        last_del = next_del;
        cnt += 1;
    }
    int next_del = getNextNumber(last_del, 1);
    cout << next_del << ">\n";
}