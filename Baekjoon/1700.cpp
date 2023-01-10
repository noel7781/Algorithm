#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, K;
vector<int> V;
vector<int> plug;
int counts[101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    int ret = 0;
    V.resize(K);
    for(auto &it: V) cin >> it;
    for(int i = 0; i < K; i++) {
        counts[V[i]]++;
    }
    for(int i = 0; i < K; i++) {
        auto it = find(plug.begin(), plug.end(), V[i]);
        if(it != plug.end()) {
            counts[*it]--;
            continue;
        }
        if(plug.size() < N) {
            plug.push_back(V[i]);
            counts[V[i]]--;
        } else {
            bool is_ok = false;
            for(int j = 0; j < plug.size(); j++) {
                if(counts[plug[j]] == 0) {
                    ret++;
                    counts[V[i]]--;
                    plug[j] = V[i];
                    is_ok = true;
                    break;
                }
            }
            if(!is_ok) {
                int last_appear = -1;
                int last_appear_idx = -1;
                for(int j = 0; j < plug.size(); j++) {
                    for(int k = i+1; k < K; k++) {
                        if(V[k] == plug[j]) {
                            if(last_appear < k) {
                                last_appear = k;
                                last_appear_idx = j;
                            }
                            break;
                        }
                    }
                }
                plug[last_appear_idx] = V[i];
                counts[V[i]]--;
                ret++;
            }

        }
    }
    cout << ret << "\n";
}