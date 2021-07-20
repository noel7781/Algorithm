#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

void solve(vector<int>& v, int n) {
    stack<int> left, right;
    for(int i = 0; i < n; ++i) {
        left.push(v[i]);
    }
    int cnt = 0;
    vector<int> ret;
    while(cnt < n) {
        int leftTop = left.top();
        if(right.empty()) {
            right.push(leftTop); 
            ret.push_back(-1);
        } else {
            int rightTop = right.top();
            if(rightTop > leftTop) {
                ret.push_back(rightTop);
            } else {
                while(rightTop <= leftTop) {
                    right.pop();
                    if(right.empty()) {
                        break;
                    }
                    rightTop = right.top();
                }
                if(right.empty()) {
                    ret.push_back(-1);
                } else {
                    ret.push_back(rightTop);
                }
            }
            right.push(leftTop); 
        }
        left.pop();
        cnt += 1;
    }
    for(auto it = ret.rbegin(); it != ret.rend(); ++it) {
        cout << *it << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    solve(v, n);
}
