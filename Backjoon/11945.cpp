#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str << "\n";
    }
}