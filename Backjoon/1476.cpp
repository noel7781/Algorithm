#include <iostream>

using namespace std;

int main() {
    int E, S, M; cin >> E >> S >> M;
    E -= 1; S -= 1; M -= 1;
    int e = 0, s = 0, m = 0;
    int ret = 1;
    while(1) {
        if(E==e && S == s && M == m) {
            break;
        }
        e += 1; e %= 15;
        s += 1; s %= 28;
        m += 1; m %= 19;
        ret += 1;
    }
    cout << ret << "\n";
}
