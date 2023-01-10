#include <bits/stdc++.h>
using namespace std;
int N; 
int main() {
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > minh;
    priority_queue<int, vector<int>, less<int> > maxh;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x <= 0) minh.push(x);
        else maxh.push(x);
    }
    int ret = 0;
    while(!minh.empty()) {
        int n1 = minh.top(); minh.pop();
        if(minh.empty()) {
            ret += n1;
            break;
        } else {
            int n2 = minh.top(); minh.pop();
            ret += n1*n2;
        }
    }
    while(!maxh.empty()) {
        int n1 = maxh.top(); maxh.pop();
        if(maxh.empty()) {
            ret += n1;
            break;
        } else {
            int n2 = maxh.top(); maxh.pop();
            if(n1 == 1 || n2 == 1) {
                ret += (n1 + n2);
            } else {
                ret += n1*n2;
            }
        }
    }
    cout << ret << "\n";
}
