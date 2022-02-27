#include <bits/stdc++.h>

#define MOD 1000000000

using namespace std;

typedef long long ll;

vector<int> prime_v;
int is_prime[40001];
bool is_over = false;
int N, M;
vector<int> A, B;
map<int, int> mA, mB;

void getPrime() {
    for(int i = 2; i <= 40000; i++) {
        is_prime[i] = 1;
    }
    for(int i = 2; i <= 40000; i++) {
        if(is_prime[i]) {
            prime_v.push_back(i);
            for(int j = i; i*j <= 40000; j++) {
                is_prime[i*j] = 0;
            }
        }
    }
    return;
}

bool checkPrime(int x) {
    if(x <= 40000) return is_prime[x];
    for(auto num: prime_v) {
        if(x % num == 0) return false;
    }
    return true;
}

void divideAndincrease(map<int, int>& m, int x) {
    for(auto num: prime_v) {
        if(num > x) break;
        while(x % num == 0) {
            m[num]++;
            x /= num;
        }
    }
    if(x > 1) m[x]++;
    return;
}

void iterate(vector<int>& v, map<int, int>& m) {
    for(auto it: v) {
        if(checkPrime(it)) {
            m[it]++;
        } else {
            divideAndincrease(m, it);
        }
    }
}

string solve() {
    auto mA_iter = mA.begin(); auto mB_iter = mB.begin();
    ll ret = 1;
    while(mA_iter != mA.end() && mB_iter != mB.end()) {
        if(mA_iter->first > mB_iter->first) {
            mB_iter++;
        } else if(mA_iter->first < mB_iter->first) {
            mA_iter++;
        } else {
            int lc = mA_iter->second; int rc = mB_iter->second;
            int mul_cnt = min(lc, rc);
            while(mul_cnt) {
                ret *= mA_iter->first;
                mul_cnt--;
                if(ret >= (ll)1e9) {
                    is_over = true;
                    ret %= MOD;
                }
            }
            mA_iter++;
            mB_iter++;
        }
    }
    string ans = to_string(ret);
    if(is_over) {
        int len = ans.length();
        string zeros;
        for(int i = 0; i < 9-len; i++) zeros += "0";
        ans = zeros + ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getPrime();
    cin >> N; A.resize(N); for(auto &it: A) cin >> it;
    cin >> M; B.resize(M); for(auto &it: B) cin >> it;
    iterate(A, mA);
    iterate(B, mB);

    cout << solve() << "\n";
}