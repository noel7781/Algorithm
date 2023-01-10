#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int l = 1, r = 0;
    int sum = 0;
    int ret = 0;
    while(r <= N) {
        if(sum == N) {
            ret++;
            sum -= l++;
        }
        if(sum < N) {
            r++;
            sum += r;
        } else if(sum > N) {
            sum -= l;
            l++;
        }    
    }
    cout << ret << "\n";
}