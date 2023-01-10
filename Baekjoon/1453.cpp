#include <bits/stdc++.h>
using namespace std;
int N;
int mark[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int ret = 0;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(mark[x]) ret++;
        mark[x] = 1;
    }
    cout << ret << "\n";
}