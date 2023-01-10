#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator vit;
int n;
vector<int> in;
vector<int> post;

void solve(vit in_begin, vit in_end, vit post_begin, vit post_end) {
    if(in_begin > in_end - 1 || post_begin > post_end - 1) return; 
    int head = *(post_end - 1);
    cout << head << " ";
    auto it = in_begin;
    while(*it != head) it++;
    int length = it - in_begin;
    solve(in_begin, it, post_begin, post_begin + length);
    solve(it+1, in_end, post_begin + length, post_end - 1);
}

int main() {
    cin >> n;
    in.resize(n);
    post.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    solve(in.begin(), in.end(), post.begin(), post.end());
}