#include <bits/stdc++.h>
using namespace std;
int N;
struct Student {
    string name;
    int kor;
    int math;
    int eng;
};
struct comp {
    bool operator()(Student& A, Student& B) {
        if(A.kor == B.kor) {
            if(A.eng == B.eng) {
                if(A.math == B.math) {
                    return A.name < B.name;
                }
                else {
                    return A.math > B.math;
                }
            } else {
                return A.eng < B.eng;
            }
        } else {
            return A.kor > B.kor;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<Student> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i].name >> V[i].kor >> V[i].eng >> V[i].math;
    }
    sort(V.begin(), V.end(), comp());
    for(int i = 0; i < N; i++) {
        cout << V[i].name << "\n";
    }
}