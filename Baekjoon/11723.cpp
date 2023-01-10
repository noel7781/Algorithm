#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M; cin >> M;
    int s = 0;
    while(M--) {
        string str; int n;
        cin >> str;
        if(str == "add") {
            cin >> n;
            s |= (1 << n);
        } else if(str == "check") {
            cin >> n;
            if(s & (1 << n)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if(str == "remove") {
            cin >> n;
            s &= ~(1 << n);
        } else if(str == "toggle") {
            cin >> n;
            s ^= (1 << n);
        } else if(str == "all") {
            for(int i = 1; i <= 20; ++i) {
                s |= (1 << i);
            }
        } else if(str == "empty") {
            s = 0;
        }
    }
}