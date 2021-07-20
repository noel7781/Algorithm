#include <iostream>

using namespace std;

int board[101][101];

int main() {
    int t; cin >> t;
    int ret = 0;
    while(t--) {
        int a, b; cin >> a >> b;
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) {
                if(!board[a+i][b+j]) {
                    ret += 1;
                    board[a+i][b+j] = 1;
                }
            }
        }
    }
    cout << ret << "\n";
}
