#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    Tree* left;
    Tree* right;
    int key;
    Tree(int k) {
        this->left = NULL;
        this->right = NULL;
        this->key = k;
    }
    void Add(int in) {
        Tree* leftptr = this->left;
        Tree* rightptr = this->right;
        if(key > in && leftptr == NULL) {
            Tree* new_t = new Tree(in);
            this->left = new_t;
        } else if(key > in && leftptr) {
            leftptr->Add(in);
        } else if(key < in && rightptr == NULL) {
            Tree* new_t = new Tree(in);
            this->right = new_t;
        } else if(key < in && rightptr) {
            rightptr->Add(in);
        }
    }
};

void post(Tree* root) {
    if(root == NULL) return;
    post(root->left);
    post(root->right);
    cout << root->key << "\n";
}

int main() {
    vector<int> v;
    int tmp = 0;
    while(cin >> tmp) {
        v.push_back(tmp);
    }
    Tree* root = new Tree(v[0]);

    for(int i = 1; i < v.size(); ++i) {
        root->Add(v[i]);
    }
    post(root);
}