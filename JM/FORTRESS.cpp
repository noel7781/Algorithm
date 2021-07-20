#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> iii;

struct Tree {
    iii info;
    Tree* parent;
    vector<Tree*> child;
    int h = 0;
};

int n;

int contains(iii a, iii b) {
    // left is bigger -> 1
    // right is bigger -> 2
    // else 0
    int rad_a = get<2>(a), rad_b = get<2>(b);
    int diff_x = get<0>(a) - get<0>(b);
    int diff_y = get<1>(a) - get<1>(b);
    double distance = pow(diff_x, 2) + pow(diff_y, 2);
    int r_d = pow(rad_a - rad_b, 2);
    if(distance > r_d) {
        return 0;
    } else {
        if(rad_a > rad_b) return 1;
        return 2;
    }
}

int addTree(Tree* t, iii coord) {
    Tree* root = t;
    //printf("Root: x %d y %d r %d\n", get<0>(t->info),get<1>(t->info),get<2>(t->info));
    int res = contains(t->info, coord);
    if(res == 1) {
        if(t->child.size() == 0) {
            Tree* newTree = new Tree;
            newTree->info = coord;
            newTree->parent = t;
            t->child.push_back(newTree);
            newTree->h = t->h + 1;
            return 1;
        } else {
            int ret = 0;
            for(int i = 0; i < t->child.size(); ++i) {
                ret |= addTree(t->child[i], coord);
            }
            if(ret == 0) {
                Tree* newTree = new Tree;
                newTree->info = coord;
                newTree->parent = t;
                t->child.push_back(newTree);
                newTree->h = t->h + 1;
                return 1;
            }
        }
    } else if(res == 2) {
        Tree* newTree = new Tree;
        newTree->info = coord;
        newTree->parent = t->parent;
        newTree->child.push_back(t);
        newTree->h = t->h;
        t->h += 1;
        return 1;
    } else {
        return 0;
    }
    return 0;
}

void printHeight(Tree* t) {
    if(t) {
        printf("x %d y %d r %d && height %d && child count: %zu\n", get<0>(t->info),get<1>(t->info),get<2>(t->info), t->h, t->child.size());
    }
    for(int i = 0; i < t->child.size(); ++i) {
        printHeight(t->child[i]);
    }
}

int height(Tree* t) {
    int ret =  1;
    if(t) {
        for(int i = 0; i < t->child.size(); ++i) {
            ret = max(ret, 1 + height(t->child[i]));
        }
    }
    return ret;
}

int solve(vector<iii>& v) {
    int ret = 0;
    Tree* t = new Tree;
    t->info = v[0];
    t->parent = NULL;
    for(int i = 1; i < v.size(); ++i) {
        addTree(t, v[i]);
    }
    printHeight(t);
    vector<int> heights(t->child.size(), 0);
    for(int i = 0; i < t->child.size(); ++i) {
        heights[i] = height(t->child[i]);
    }
    sort(heights.rbegin(), heights.rend());
    ret = heights[0] + heights[1];
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        vector<iii> v;
        for(int i = 0; i < n; ++i) {
            int x, y, r; cin >> x >> y >> r;
            v.push_back(make_tuple(x, y, r));
        }
        cout << solve(v) << "\n";
    }
}
