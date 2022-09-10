#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
bool isPrime(ll x) {
    if(x <= 1) return false;
    if(x <= 3) return true;
    int lim = int(sqrt(x))+1;
    for(int i = 2; i <= lim; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str = "";
    while(n) {
        int adder = n % k;
        n /= k;
        str += (adder+'0');
    }
    reverse(str.begin(), str.end());
    string part;
    stringstream ss(str);
    vector<ll> v;
    while(getline(ss, part, '0')) {
        if(part.size() > 0) {
            v.push_back(stoll(part));
            v.push_back(0LL);
        }
    }
    v.pop_back();
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0) continue;
        if(isPrime(v[i])) {
            answer++;
        }
    }
    
    return answer;
}