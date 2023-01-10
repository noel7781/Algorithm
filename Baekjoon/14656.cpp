#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        if(x != i) ret++;
    }
    cout << ret << "\n";
}