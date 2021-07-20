#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#define MAX 40000 // sqrt(1e9) + 1;
#define MOD 1000000000

using namespace std;

typedef long long ll;

int prime[MAX+1];
int N[MAX+1];
int M[MAX+1];
map<int, int> n_over;
map<int, int> m_over;

vector<int> primes;

void getPrime() {
    for(int i = 0; i <= MAX; ++i) {
        prime[i] = 1;
    }
    prime[0] = 0; prime[1] = 0;
    for(int i = 2; i <= MAX; ++i) {
        if(prime[i]) primes.push_back(i);
        for(int j = 2; i*j <= MAX; ++j) {
            prime[i*j] = 0;
        }
    }
}

void add_arr(int arr[], int k, bool m) {
    for(int i = 0; i < primes.size(); ++i) {
        int count = 0;
        while(k % primes[i] == 0) {
            k /= primes[i];
            count += 1;
        }
        arr[primes[i]] += count;
        if(k == 1) break;
    }
    if(k != 1 && m) n_over[k]++;
    else if(k != 1) m_over[k]++;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("./test_file/zadaca.in.8", "r", stdin);
    getPrime();
    int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int k; cin >> k;
        add_arr(N, k, 0);
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int k; cin >> k;
        add_arr(M, k, 1);
    }

    ll ret = 1;
    bool check_over = false;
    for(int i = 2; i <= MAX; ++i) {
        ll mul_cnt = min(N[i], M[i]);
        if(mul_cnt < 1) continue;
        else {
            while(mul_cnt > 0) {
                ret *= i;
                if(ret > 1e9) check_over = true;
                mul_cnt--;
                ret %= MOD;
            }
        }
    }
    for(auto it = n_over.begin(); it != n_over.end(); ++it) {
        int num = it->first;
        auto it_2 = m_over.find(num);
        if(it_2 != m_over.end()) {
            int mul_cnt = min(it->second, it_2->second);
            while(mul_cnt > 0) {
                ret *= num;
                if(ret > 1e9) check_over = true;
                mul_cnt--;
                ret %= MOD;
            }
        }
    }


    string ans = to_string(ret);
    if(check_over) {
        int len = ans.length();
        for(int i = 0; i < 9-len; ++i) {
            ans = "0" + ans;
        }
    }
    cout << ans << "\n";
}