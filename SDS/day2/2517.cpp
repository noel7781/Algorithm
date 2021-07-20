#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

struct segTree() {
    int n;
    void init(vector<int>& v) {
        n = v.size();
        arr.assign(4*n, 0);
    }
}

int main() {
    cin >> n;
    v.assign(n, 0);
    for(auto &it: v) {
        cin >> it;
    }
    segTree t(v);
}