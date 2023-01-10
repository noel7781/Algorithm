#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
string A, target;
bool isPrime[10000];
void getPrime() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = 0; isPrime[1] = 0;
    for(int i = 2; i < 10000; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j < 10000; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}
int search(string& A) {
    vector<int> dists(10000, 1e9);
    dists[stoi(A)] = 0;
    priority_queue<pis, vector<pis>, greater<pis> > pq;
    pq.push({0, A});
    while(!pq.empty()) {
        auto [cost, cur_num_str] = pq.top(); pq.pop();
        if(cur_num_str == target) {
            return cost;
        }
        if(dists[stoi(cur_num_str)] < cost) continue;
        for(int j = 0; j < 4; j++) {
            char org = cur_num_str[j];
            for(int k = 0; k <= 9; k++) {
                if(j == 0 && k == 0) continue;
                cur_num_str[j] = k+'0';
                int num = stoi(cur_num_str);
                if(isPrime[num] && dists[num] > cost+1) {
                    dists[num] = cost+1;
                    pq.push({cost+1, cur_num_str});
                }
            }
            cur_num_str[j] = org;
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    getPrime();
    int t; cin >> t;
    while(t--) {
        cin >> A >> target;
        int ret = search(A);
        if(ret == -1) {
            cout << "Impossible\n";
        } else {
            cout << ret << "\n";
        }
    }

}