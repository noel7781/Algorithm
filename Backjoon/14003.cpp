#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll S[1000001];
int idx_record[1000001];

int lis() {
    int ret = 0;
    vector<ll> result;
    int idx = 1;
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(result.begin(), result.end(), S[i]);
        if(it == result.end()) {
            result.push_back(S[i]);
            ret += 1;
            idx_record[i] = idx;
            idx += 1;
        } else {
            idx_record[i] = it - result.begin() + 1;
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
    int answer = lis();
    cout << answer << "\n";
    vector<int> result;

    for(int i = n-1; i >= 0; --i) {
        if(idx_record[i] == answer) {
            result.push_back(S[i]);
            answer -= 1;
        }
    }
    for(auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << *it << " ";
    }
}


