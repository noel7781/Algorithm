#include <bits/stdc++.h>
using namespace std;
int N;
bool isPrime(int n) {
    if(n == 1) return false;
    if(n <= 3) return true;
    int lim = int(sqrt(n)) + 1;
    for(int i = 2; i <= lim; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
bool isPalindrome(int n) {
    string str = to_string(n);
    int len = str.size();
    for(int i = 0; i < len/2; i++) {
        if(str[i] != str[len-1-i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(1) {
        if(isPalindrome(N)) {
            if(isPrime(N)) {
                cout << N << "\n";
                return 0;
            }
        }
        N++;
    }

}