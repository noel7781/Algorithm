#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll S[1000001];

int lis() {
    int ret = 0;
    vector<ll> result;
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(result.begin(), result.end(), S[i]);
        if(it == result.end()) {
            result.push_back(S[i]);
            ret += 1;
        } else {
            *it = S[i];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    cout << lis() << "\n";
}


