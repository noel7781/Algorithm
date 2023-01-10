#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    Tree* left, *right;
    char name;
    Tree(char c) {
        this->left = NULL;
        this->right = NULL;
        this->name = c;
    }
};

int n;

void pre(Tree* t) {
    if(t == NULL) return;
    cout << t->name;
    pre(t->left);
    pre(t->right);
}
void in(Tree* t) {
    if(t == NULL) return;
    in(t->left);
    cout << t->name;
    in(t->right);
}
void post(Tree* t) {
    if(t == NULL) return;
    post(t->left);
    post(t->right);
    cout << t->name;
}

int main() {
    cin >> n;
    vector<Tree*> t;
    for(int i = 0; i < n; ++i) {
        Tree* new_t = new Tree(i+65);
        t.push_back(new_t);
    }
    for(int i = 0; i < n; ++i) {
        char c1, c2, c3; cin >> c1 >> c2 >> c3;
        if(c2 != '.')
            t[(int)c1-65]->left = t[(int)c2-65];
        if(c3 != '.')
            t[(int)c1-65]->right = t[(int)c3-65];
    }
    pre(t[0]);
    cout << "\n";
    in(t[0]);
    cout << "\n";
    post(t[0]);
}