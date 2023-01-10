#include <bits/stdc++.h>
using namespace std;
int N; 
vector<string> V;
bool check(string& left, string& right) {
    bool is_same = true;
    for(int i = 0; i < min(left.size(), right.size()); i++) {
        if(left[i] != right[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool is_bad = false;
        for(int j = i+1; j < N; j++) {
            if(check(V[i], V[j])) {
                is_bad = true;
                break;
            }
        }
        if(!is_bad) ans++;
    }

    cout << ans << "\n";
}