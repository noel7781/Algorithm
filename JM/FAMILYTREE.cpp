/*
 *    For the Future... 2020/08/17
 */
#include <iostream>
#include <vector>

using namespace std;

struct LCA {
    int n;
    vector<int> rangeAncestor;
    LCA(const vector<int>& arr) {
        n = arr.size();
        rangeAncestor.resize(4*n);
        init(arr, 0, n-1, 1);
    }
    int init(const vector<int>& arr, int left, int right, int node) {
        
    }
};

int main() {
    int T; cin >> T;
    while(T--) {
        int size, q; cin >> size >> q;
        vector<int> arr(size);
        for(int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
        struct LCA t(arr);
        while(q--) {
            int a, b; cin >> a >> b;

        }
                      
    }
}
