#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > counts;
vector<int> lengths;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    counts.resize(N, vector<int>(26, 0));
    lengths.resize(N, 0);
    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        for(const auto& c: str) {
            counts[i][c-'A']++;
        }
        lengths[i] = str.length();
    }
    int ans = 0;
    for(int j = 1; j < N; j++) {
        if(abs(lengths[0] - lengths[j]) > 1) continue;
        int sum = 0;
        for(int k = 0; k < 26; k++) {
            sum += abs(counts[j][k] - counts[0][k]);
        }
        if(sum <= 2) {
            ans++;
        }
    }
    cout << ans << "\n";
}