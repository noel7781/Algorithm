#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[10];

int main() {
    string n; cin >> n;
    for(int i = 0; i < n.size(); ++i) {
        arr[n[i]-'0'] += 1;
    }
    int ret = 0;
    for(int i = 0; i < 10; ++i) {
        if(i==6 || i == 9) continue;
        ret = max(ret, arr[i]);
    }
    int comp = (arr[6] + arr[9]);
    ret = max(ret, (comp+1)/2);
    cout << ret << "\n";
}
