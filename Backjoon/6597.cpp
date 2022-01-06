#include <bits/stdc++.h>

using namespace std;

void solve(string pre, string in) {
    if(pre.length() == 0) {
        return;
    }
    if(pre.length() == 1) {
        cout << pre[0];
        return;
    }
    char r = pre[0];
    int slice_point = 0;
    for(; slice_point < (int)in.size(); slice_point++) {
        if(r == in[slice_point]) {
            break;
        }
    }
    solve(pre.substr(1, slice_point), in.substr(0, slice_point));
    solve(pre.substr(slice_point+1), in.substr(slice_point+1));
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.in", "r", stdin);
    while(cin) {
        string pre, in; cin >> pre >> in;
        solve(pre, in);
        cout << "\n";
    }
}