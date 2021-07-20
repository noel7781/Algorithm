#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int g_count = 1;
int n;
int result[500001];

struct Tree {
    int key;
    int size;
    Tree *left, *right;

    Tree(int n) : key(n), size(1), left(NULL), right(NULL) {
    
    }
    
    void setLeft(Tree* node) {
        left = node;
        calc_size();
    }

    void setRight(Tree* node) {
        right = node;
        calc_size();
    }

    void calc_size() {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

int kth(Tree* root, int k) {
    int leftSize = 0;
    if(root->left) leftSize = root->left->size;
    if(k == leftSize+1) return root->key;
    if(k < leftSize+1) {
        return kth(root->left, k);
    }
    return kth(root->right, k - leftSize - 1);
}

Tree* insert(Tree* root, int k, Tree* next) {
    if(root == NULL) return next;
    int rightSize = 0;
    if(root->right) rightSize = root->right->size;
    
    if(k <= rightSize) {
        root->setRight(insert(root->right, k, next));
    } else if(k > rightSize) {
        root->setLeft(insert(root->left, k-rightSize-1, next));
    }
    return root;
}

void setValue(Tree* root) {
    if(root->left) setValue(root->left);
    result[root->key] = g_count;
    g_count += 1;
    if(root->right) setValue(root->right);
}

void solve(vector<int>& v) {
    Tree* root = new Tree(1);
    for(int i = 1; i < n; ++i) {
        root = insert(root, v[i], new Tree(i+1)); 
    }
    setValue(root);
    for(int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

}

int main() {
    int t; cin >> t;
    while(t--) {
        g_count = 1;
        cin >> n;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        solve(v);
    }
}
