#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 

int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    if(a < b) swap(a, b);
    a %= b;
    return gcd(a, b);
}

int get_gcd(vector<int>& arr) {
    int ret = gcd(arr[1]-arr[0], arr[1]-arr[0]);
    for(int i = 1; i < n-1; ++i) {
        ret = gcd(ret, arr[i+1]-arr[i]);
    }
    return ret;
}

int main() {
    cin >> n;
    vector<int> v(n);
    for(auto &it: v) cin >> it;
    sort(v.begin(), v.end());
    int v2_gcd = get_gcd(v);
    vector<int> result;
    for(int i = 1; i*i <= v2_gcd; ++i) {
        if(v2_gcd % i == 0) {
            if(i != 1) result.push_back(i);
            result.push_back(v2_gcd / i);
        }
    }
    sort(result.begin(), result.end());
    auto last = unique(result.begin(), result.end());
    result.erase(last, result.end());
    for(auto x : result) {
        cout << x << " ";
    }
}