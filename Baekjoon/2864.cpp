#include <bits/stdc++.h>
using namespace std;
string A, B;
int main() {
    cin >> A >> B;
    for(int i = 0; i < A.size(); i++) if(A[i] == '6') A[i] = '5';
    for(int i = 0; i < B.size(); i++) if(B[i] == '6') B[i] = '5';
    int min_v = stoi(A) + stoi(B);
    for(int i = 0; i < A.size(); i++) if(A[i] == '5') A[i] = '6';
    for(int i = 0; i < B.size(); i++) if(B[i] == '5') B[i] = '6';
    int max_v = stoi(A) + stoi(B);
    cout << min_v << " " << max_v << "\n";
}