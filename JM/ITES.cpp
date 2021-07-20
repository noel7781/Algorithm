#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

ull k, n;

int solve() {
    ull A = 1983;
    deque<ull> signal;
    int ret = 0;
    int cnt = 0;
    ull sum = 0;
    while(cnt < n) {
        ull nextSignal = A % 10000 + 1;
        A = (A * 214013 + 2531011) % ((ull)(1) << 32);
        signal.push_back(nextSignal);
        sum += signal.back();
        if(sum == k) {
            ret += 1;
            sum -= signal.front();
            signal.pop_front();
        } else if(sum > k) {
            while(sum > k) {
                sum -= signal.front();
                signal.pop_front();
            }
            if(sum == k) {
                ret += 1;
                sum -= signal.front();
                signal.pop_front();
            }
        }
        cnt += 1;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> k >> n;
        cout << solve() << "\n";
    }
}
