#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[3];
    for(int i = 0; i< 3; i++) {
        cin >> arr[i];
    }
    int maxv = max({arr[0], arr[1], arr[2]});
    int minv = min({arr[0], arr[1], arr[2]});
    int maxc=0, minc = 0;
    for(int i = 0; i < 3; i++) {
        if(maxv == arr[i]) maxc++;
        if(minv == arr[i]) minc++;
    }
    if(maxc == 3) {
        cout << 10000 + maxv*1000 << "\n";
    } else if(maxc == 1 && minc == 1) {
        cout << maxv * 100 << "\n";
    } else {
        if(maxc == 2) {
            cout << 1000 + maxv * 100 << "\n";
        } else {
            cout << 1000 + minv * 100 << "\n";
        }
    }
    return 0;
}