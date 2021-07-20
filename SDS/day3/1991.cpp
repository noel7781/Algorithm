#include <iostream>
#include <vector>

using namespace std;

int n;

struct Tree {
    char c;
    Tree* left, *right;
    Tree() :left(NULL), right(NULL) {
    }
};

void preorder(Tree* t) {
    if(!t) return;
    if(t) cout << t->c;
    if(t->left) preorder(t->left);
    if(t->right) preorder(t->right);
}
void inorder(Tree* t) {
    if(!t) return;
    if(t->left) inorder(t->left);
    if(t) cout << t->c;
    if(t->right) inorder(t->right);
}
void postorder(Tree* t) {
    if(!t) return;
    if(t->left) postorder(t->left);
    if(t->right) postorder(t->right);
    if(t) cout << t->c;
}
int main() {
    cin >> n;
    vector<vector<char> > tree(n, vector<char>(3, '.'));
    for(int i = 0; i < n; ++i) {
        cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }
    Tree* t = new Tree[n];
    for(int i = 0; i <n; ++i) {
        t[i].c = 'A' +i;
    }
    for(int i = 0; i < n; ++i) {
        if(tree[i][1] != '.')
            t[tree[i][0] - 'A'].left = &t[tree[i][1]-'A'];
        if(tree[i][2] != '.')
            t[tree[i][0] - 'A'].right = &t[tree[i][2]-'A'];
    }
    preorder(&t[0]);
    cout << "\n";
    inorder(&t[0]);
    cout << "\n";
    postorder(&t[0]);
    cout << "\n";
}