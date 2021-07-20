#include <iostream>
#include <vector>
#include <cstring>
#include <random>

#define MOD 20090711

using namespace std;

typedef long long ll;

ll n, a, b;
ll arr[200001];
struct Node {
    ll key;
    int size;
    int priority;
    Node *left, *right;

    Node(int k) : key(k), size(1), priority(rand()), left(NULL), right(NULL) {

    }
    
    void setLeft(Node* node) {
        left = node;
        calc_size();
    }

    void setRight(Node* node) {
        right = node;
        calc_size();
    }
    
    void calc_size() {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, ll key) {
    if(root == NULL) return NodePair(NULL, NULL);
    if(root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
    if(root == NULL) return node;
    int rootValue = root->key;
    int newValue = node->key;
    if(node->priority > root->priority) {
        NodePair splitted = split(root, newValue);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    } else {
        if(newValue > rootValue) {
            root->setRight(insert(root->right, node));
        } else {
            root->setLeft(insert(root->left, node));
        }
    }
    return root;
}

Node* kth(Node* root, ll k) {
    int leftSize = 0;
    if(root->left) leftSize = root->left->size;
    if(k == leftSize+1) {
        return root;
    } else if(k < leftSize+1) {
        return kth(root->left, k);
    } else {
        return kth(root->right, k - leftSize - 1);
    }
}

void calc_arr() {
    arr[0] = 1983;
    for(int i = 1; i < n; ++i) {
        arr[i] = (arr[i-1] * a + b) % MOD;
    }
}

int solve() {
    int ret = 0;
    Node* root = NULL;
    for(int i = 0; i < n; ++i) {
        root = insert(root, new Node(arr[i]));
        int add = kth(root, i/2+1)->key;
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        calc_arr();
        cout << solve() << "\n";
    }
}
