#include <bits/stdc++.h>

using namespace std;

int A, B, C;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;
    int minutes = B+C;
    A += (minutes/60);
    A %= 24;
    minutes %= 60;
    cout << A << " " << minutes << "\n";
}