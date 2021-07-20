#include <iostream>

using namespace std;

int get_5(int n) {
    int cnt = 0;
    while(n > 0) {
        cnt += n/5;
        n /= 5;
    }
    return cnt;
}
int get_2(int n) {
    int cnt = 0;
    while(n > 0) {
        cnt += n/2;
        n /= 2;
    }
    return cnt;
}
int main() {
    int n, m; cin >> n >> m;
    cout << min(get_5(n) - get_5(m) - get_5(n-m), get_2(n) - get_2(m) - get_2(n-m));
}