#include <bits/stdc++.h>
using namespace std;
int N, M;
map<string, string> m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s1, s2; cin >> s1 >> s2;
        m[s1] = s2;
    }
    for(int i = 0; i < M; i++) {
        string s1; cin >> s1;
        cout << m[s1] << "\n";
    }
}