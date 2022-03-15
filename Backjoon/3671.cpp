#include <bits/stdc++.h>
#define MAXN 10000000
using namespace std;
int ans = 0;
bool is_visit[MAXN];
bool is_prime[MAXN];
void get_prime() {
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int j = 2; j <= MAXN; j++) {
        if(is_prime[j]) {
            for(long long i = (long long)j*j; i <= MAXN; i += j) {
                is_prime[i] = 0;
            }
        }
    }
}
void search(string& s, int state, string& num) {
    if(num != "") {
        int inum = stoi(num);
        if(!is_visit[inum] && is_prime[inum]) ans++;
        is_visit[inum] = 1;
    }
    for(int i = 0; i < s.size(); i++) {
        if(state & (1 << i)) continue;
        num.push_back(s[i]);
        search(s, state | (1 << i), num);
        num.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    memset(is_prime, 1, sizeof(is_prime));
    get_prime();
    while(t--) {
        memset(is_visit, 0, sizeof(is_visit));
        ans = 0;
        string str; cin >> str;
        string acc = "";
        search(str, 0, acc);
        cout << ans << "\n"; 
    }
}