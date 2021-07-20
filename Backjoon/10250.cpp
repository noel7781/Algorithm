#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int H, W, N; cin >> H >> W >> N;
        int floor = (N-1) % H + 1;
        int number = (N-1) / H + 1;
        string room_number = number >= 10 ? to_string(number) : "0"+to_string(number);
        string ret = to_string(floor) + room_number;
        cout << ret << "\n";
    }
}
