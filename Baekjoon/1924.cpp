#include <bits/stdc++.h>
using namespace std;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> p = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int M, D;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> D;
    int day = 0;
    for(int i = 1; i < M; i++) {
        day += days[i];
    }
    day += (D-1);
    cout << p[day % 7] << "\n";

}