#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A, B; cin >> A >> B;
    vector<int> v_a(A); for(auto &it: v_a) cin >> it;
    vector<int> v_b(B); for(auto &it: v_b) cin >> it;
    sort(v_a.begin(), v_a.end());
    sort(v_b.begin(), v_b.end());
    auto a_iter = v_a.begin();
    auto b_iter = v_b.begin();
    int acc = 0;
    while(a_iter < v_a.end() && b_iter < v_b.end()) {
        int a = *a_iter, b = *b_iter;
        if(a < b) a_iter++;
        else if(a > b) b_iter++;
        else {
            a_iter++; b_iter++; acc++;
        }
    }
    cout << A+B-2*acc << "\n";
}