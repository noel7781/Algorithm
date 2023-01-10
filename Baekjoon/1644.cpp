#include <bits/stdc++.h>

using namespace std;

bool is_prime[4000001];
vector<int> prime;
int target = 0; 

void setPrime() {
    is_prime[1] = false;
    for(int i = 2; i <= 4000000; ++i) {
        if(is_prime[i]) {
            prime.push_back(i);
            if(i >= 2000) continue;
            int j = i;
            while(i * j <= 4000000) {
                is_prime[i * j++] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(is_prime, true, sizeof(is_prime));
    setPrime();
    cin >> target;
    int ans = 0;
    int sz = prime.size();
    int acc = 0;
    int l = 0, r = 0;
    for(int l = 0; l < sz; l++) {
        while(acc < target && r < sz) {
            acc += prime[r++];
        }
        if(acc == target) {
            ans++;
        }
        acc -= prime[l];
    }
    cout << ans << "\n";
}