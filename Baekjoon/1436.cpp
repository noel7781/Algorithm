#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int cnt = 0;
    int start = 665;
    string str;
    int N; cin >> N;
    while(cnt < N) {
        start += 1;
        str = to_string(start);
        if(str.find("666") != -1)
            cnt += 1;
    } 
    cout << start << "\n";
}