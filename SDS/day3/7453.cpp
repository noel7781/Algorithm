#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<int> a,b,c,d;
vector<int> ab, cd;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int u, v, w, x;
        cin >> u >> v >> w >> x;
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        d.push_back(x);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    }

    // 1. 정렬 없이 바로 map

    // 2. 정렬
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    ll ret = 0;
    int p1 = 0, p2 = n*n-1;
    while(p1 < n*n && p2 >= 0) {
        int sum = ab[p1] + cd[p2];
        if(sum == 0) {
            int next_p1 = p1+1;
            int next_p2 = p2-1;
            while(next_p1 < n*n && ab[p1] == ab[next_p1]) {
                next_p1 += 1;
            }
            while(next_p2 >= 0 && cd[p2] == cd[next_p2]) {
                next_p2 -= 1;
            }
            ret += (next_p1-p1)*(p2-next_p2);
        }
        if(sum <= 0 && ab[p1] <= 0) {
            p1++;
        } else if(sum <= 0 && ab[p1] > 0) {
            p1++;
        } else if(sum > 0 && ab[p1] <= 0) {
            p2--;
        } else if(sum > 0 && ab[p1] > 0) {
            p2--;
        }
    }
    // ll cnt = 0;
    // for(p1 = 0; p1 < n*n; p1++) {
    //     int target = -ab[p1];
    //     if(p1 > 0 && ab[p1] == ab[p1-1]) {
    //         ret += cnt;
    //     }
    //     else {
    //         while(p2 >= 0 && target < cd[p2]) {
    //             p2--;
    //         }
    //         cnt = 0;
    //         while(p2 >= 0 && target == cd[p2]) {
    //             cnt++;
    //             p2--;
    //         }
    //         ret += cnt;
    //     }
    // }
    cout << ret << "\n";
}