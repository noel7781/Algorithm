#include <bits/stdc++.h>
using namespace std;
int counts[100002];
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int x;
    for(int i = 0; i < N; i++) {
        cin >> x; counts[x]++;
    }
    long long ret = 0;
    for(int i = 1; i <= 100000; i++) {
        while(counts[i]) {
            counts[i]--;
            for(int j = i+1; j <= 100001; j++) {
                if(counts[j]) {
                    counts[j]--;
                } else {
                    ret += (long long)(j-1) * (j-i);
                    break;
                }
            }
        }
    }
    cout << ret << "\n";
}