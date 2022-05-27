#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    scanf("%d", &N);
    long long ret = 1;
    for(int i = 2; i <= N; i++) {
        ret *= i;
        while(ret % 10 == 0) ret /= 10;
        ret %= 1000000000000;
    }
    printf("%05lld\n", ret % 100000);
}