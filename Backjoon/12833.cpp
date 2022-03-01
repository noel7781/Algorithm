#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    int ret = (C & 1) ? A ^ B : A;
    cout << ret << "\n";
}