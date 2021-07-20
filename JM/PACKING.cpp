#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

/*
typedef tuple<string, int, int> tsii;

int t;
int n, w;
int cache[102][1001];
int choices[102][1001];

int solve(vector<tsii>& v, int pos, int packed_weight) {
    int& ret = cache[pos+1][packed_weight];
    if(ret != -1)
        return ret;
    ret = 0;

    int bestNext = -1;
    for(int next = pos+1; next < n; ++next) {
        if(pos == -1) {
            int cand = solve(v, next, packed_weight);
            if(cand > ret) {
                ret = cand;
                bestNext = next;
            }
        } else {
            int nextWeight = packed_weight + get<1>(v[pos]);
            if(nextWeight <= w) {
                int cand = get<2>(v[pos]) + solve(v, next, nextWeight);
                if(cand > ret) {
                    ret = cand;
                    bestNext = next;
                }
            }
        }
    }
    choices[pos+1][packed_weight] = bestNext;
    return ret;
}

void reconstruct(vector<tsii>& v, int start, int packed_weight, vector<int>& seq) {
    int nextWeight = (start == -1) ? 0 : packed_weight + get<1>(v[start]);
    if(start != -1) {
        seq.push_back(start);
    }
    int next = choices[start+1][packed_weight];
    if(nextWeight > w) {
        seq.pop_back();
        return;
    }
    if(next != -1) reconstruct(v, next, nextWeight, seq);
}

int main() {
    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> w;
        vector<tsii> v;
        for(int i = 0; i < n; ++i) {
            string a; int b, c;
            cin >> a >> b >> c;
            tsii input = make_tuple(a, b, c);
            v.push_back(input);
        }
        int result = solve(v, -1, 0);
        vector<int> result_idx;
        reconstruct(v, -1, 0, result_idx);
        cout << result << " " << result_idx.size() << "\n";
        for(int i = 0; i < result_idx.size(); ++i) {
            int now = result_idx[i];
            cout << get<0>(v[now]) << "\n";
        }
    }
}
*/

int n, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];

int pack(int capacity, int item) {
    if(item == n) return 0;
    int& ret = cache[capacity][item];
    if(ret != -1) return ret;
    // 물건을 안챙기는 경우
    ret = pack(capacity, item+1);
    // 물건을 챙기는 경우
    if(capacity >= volume[item]) {
        ret = max(ret, pack(capacity-volume[item], item+1) + need[item]);
    }
    return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
    if(item == n) return;
    if(pack(capacity, item) == pack(capacity, item+1)) {
        reconstruct(capacity, item+1, picked);
    } else {
        picked.push_back(name[item]);
        reconstruct(capacity-volume[item], item+1, picked);
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> capacity;
        for(int i = 0; i < n; ++i) {
            cin >> name[i] >> volume[i] >> need[i];
        }
        int ret = pack(capacity, 0);
        vector<string> picked;
        reconstruct(capacity, 0, picked);
        cout << ret << " " << picked.size() << "\n";
        for(int i = 0; i < picked.size(); ++i) {
            cout << picked[i] << "\n";
        }
    }
}
