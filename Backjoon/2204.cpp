#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> V;
string toLower(string s) {
    transform(
        s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); }
    );
    return s;
}
bool comp(string& A, string& B) {
    return toLower(A) < toLower(B);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1) {
        cin >> N;
        if(N == 0) return 0;
        V.resize(N);
        for(auto &it: V) cin >> it;
        sort(V.begin(), V.end(), comp);
        cout << V[0] << "\n";
    }
}