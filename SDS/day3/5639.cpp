#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void recur(int s, int e) {
    // v[s] == root(전위순회인 경우)
    if(s == e) {
        printf("%d\n", v[s]);
        return;
    } else if(s > e) {
        return;
    } else {
        // left
        int k = s+1;
        for(k; k <= e; ++k) {
            if(v[k] >= v[s]) break;
        }
        recur(s+1, k-1);
        // right
        recur(k, e);
        // mid
        printf("%d\n", v[s]);
    }
}

int main() {
    freopen("test.in", "r", stdin);
    int next;
    while(scanf("%d", &next) != -1) {
        v.push_back(next);
    }
    int sz = v.size()-1;
    recur(0, sz);

}