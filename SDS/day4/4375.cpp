#include <iostream>

using namespace std;

int getLength(int n) {
    int ret = 1;
    string str = "1";
    while(true) {
        while(stoi(str) < n) {
            str = to_string(stoi(str) * 10 + 1);
            ret += 1;
        }
        if(stoi(str) >= n) {
            int next = stoi(str) % n;
            if(next == 0) return ret;
            str = to_string(next);
        }
    }
    return ret;
}

int main() {
    // freopen("test.in", "r", stdin);
    int n = 1;
    while(scanf("%d", &n) != -1) {
        int ret = getLength(n);
        cout << ret << "\n";
    }
}