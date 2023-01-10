#include <bits/stdc++.h>
#define MAXN 100000000
using namespace std;
int N;
int subs[] = {1, 3, 5, 7, 9};
bool isPrime(int x) {
    int lim = sqrt(x);
    for(int j = 2; j <= lim+1; j++) {
        if(x % j == 0) return false;
    }
    return true;
}
void search(int num, int len) {
    if(len == N) {
        cout << num << "\n";
        return;
    }
    num *= 10;
    for(auto sub: subs) {
        if(isPrime(num+sub)) {
            search(num+sub, len+1);
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    search(2, 1);
    search(3, 1);
    search(5, 1);
    search(7, 1);
}