#include <bits/stdc++.h>
using namespace std;
int N, M;
unordered_map<string, int> s2i;
vector<string> s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    s.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> s[i];
        s2i.insert({s[i], i});
    }
    for(int i = 0; i < M; i++) {
        string input; cin >> input;
        if('0' <= input[0] && '9' >= input[0]) {
            cout << s[stoi(input)] << "\n";
        } else {
            cout << s2i[input] << "\n";
        }
    }
}