#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> V;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    ll ret = 0;
    for(int s1 = 0; s1 < N-2; s1++) {
        int s2 = s1+1, s3 = N-1;
        while(s2 < s3) {
            int sum = V[s1] + V[s2] + V[s3];
            if(sum < 0) {
                s2++;
            } else if(sum > 0) {
                s3--;
            } else {
                int l = 1, r = 1;
                if(V[s2] == V[s3]) {
                    int cnt = s3-s2;
                    ret += (cnt * (cnt+1))/2;
                    break;
                } else {
                    while(s2+l < s3) {
                        if(V[s2] == V[s2+l]) {
                            l++;
                        } else {
                            break;
                        }
                    }
                    while(s2 < s3-r) {
                        if(V[s3] == V[s3-r]) {
                            r++;
                        } else {
                            break;
                        }
                    }
                    ret += (l * r);
                }
                s2 += l;
                s3 -= r;
            }
        }
    }
    cout << ret << "\n";
}