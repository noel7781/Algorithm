#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct info {
    int start;
    int end;
    int term;
};

int n, k;

bool check(vector<info>& Info, int pos) {
    int count = 0;
    for(int i = 0; i < Info.size(); ++i) {
        if(pos < Info[i].start) continue;
        if(pos >= Info[i].end) {
            count += (Info[i].end - Info[i].start) / Info[i].term + 1;
        } else {
            count += (pos - Info[i].start) / Info[i].term + 1;
        }
    }
    if(count >= k) return true;
    return false;
}

int solve(vector<info>& Info) {
    int ret = 0;
    int lo = 0, hi = 8030001;
    while(lo+1 < hi) {
        int mid = (lo + hi) / 2;
        if(check(Info, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<info> Info;
        for(int i = 0; i < n; ++i) {
            int s, e, t; cin >> s >> e >> t;
            info k = {s-e, s, t};
            Info.push_back(k);
        }
        cout << solve(Info) << "\n";
    }
}
