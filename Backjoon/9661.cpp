#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N % 5 == 0 || N % 5 == 2) cout << "CY\n";
    else cout << "SK\n";
}