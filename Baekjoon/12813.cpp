#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string A, B; cin >> A >> B;
    for(int i = 0; i < A.length(); i++) {
        A[i] -= '0';
        B[i] -= '0';
    }
    for(int i = 0; i < A.length(); i++) {
        cout << (A[i] & B[i]);
    }
    cout << "\n";
    for(int i = 0; i < A.length(); i++) {
        cout << (A[i] | B[i]);
    }
    cout << "\n";
    for(int i = 0; i < A.length(); i++) {
        cout << (A[i] ^ B[i]);
    }
    cout << "\n";
    for(int i = 0; i < A.length(); i++) {
        cout << (A[i] ^ 1);
    }
    cout << "\n";
    for(int i = 0; i < A.length(); i++) {
        cout << (B[i] ^ 1);
    }
    cout << "\n";
}