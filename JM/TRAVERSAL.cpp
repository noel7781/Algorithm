#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;

vector<int> slice(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    const int N = preorder.size();
    if(preorder.empty()) return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - L - 1;
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
    cout << root << " ";
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        vector<int> pre(n, 0);
        vector<int> in(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> pre[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> in[i];
        }
        printPostOrder(pre, in);
        cout << "\n";
    }
}
