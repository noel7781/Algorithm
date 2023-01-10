#include <iostream>
#include <vector>

using namespace std;

int calculate_gcd(int a, int b) {
    int bigger = max(a, b);
    int smaller = min(a, b);
    while(bigger != smaller) {
        if(bigger % smaller != 0)
            bigger %= smaller;
        else 
            return smaller;
        swap(bigger, smaller);
    }
    return bigger;
}

int solve(int a, int b) {
    int gcd = calculate_gcd(a, b);
    return a * b / gcd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
}
