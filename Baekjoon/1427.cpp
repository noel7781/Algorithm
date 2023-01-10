#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int N; cin >> N;
    while(N > 0) {
        int rem = N % 10;
        v.push_back(rem);
        N -= rem;
        N /= 10;
    }
    sort(v.begin(), v.end(), greater<int>());
    for(auto x: v) {
        cout<<x;
    }
}