#include <bits/stdc++.h>
using namespace std;
string A, B; 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    if(A.length() < B.length()) swap(A, B);
    int diff = 100;
    for(int i = 0; i <= A.length() - B.length(); i++) {
        int tmp = 0;
        for(int j = 0; j < B.length(); j++) {
            if(A[i+j] != B[j]) tmp++;
        }
        diff = min(diff, tmp);
    }
    cout << diff << "\n";
}