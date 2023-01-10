#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

typedef long long ll;

class SquareMatrix {
    private:
        ll** arr;
        int size;
    public:
        SquareMatrix(int n=2): size(n) {
            arr = new ll*[size];
            for(int i = 0; i < size; ++i) {
                arr[i] = new ll[size];
            }
        }
        /*
        ~SquareMatrix() {
            for(int i = 0; i < size; ++i) {
                delete[] arr[i];
            }
            delete[] arr;
        }
        */
        SquareMatrix& operator*(SquareMatrix &b) {
            SquareMatrix result(size);
            for(int i = 0; i < size; ++i) {
                for(int j = 0; j < size; ++j) {
                    result.arr[i][j] = 0;
                }
            }

            for(int i = 0; i < size; ++i) {
                for(int j = 0; j < size; ++j) {
                    for(int k = 0; k < size; ++k) {
                        result.arr[i][j] += (arr[i][k] * b.arr[k][j]);
                        result.arr[i][j] %= MOD;
                    }
                }
            }

            for(int i = 0; i < size; ++i) {
                for(int j = 0; j < size; ++j) {
                    arr[i][j] = result.arr[i][j];
                }
            }
            return *this;
        }
        ll* operator[](int i) {
            return arr[i];
        }

};

SquareMatrix identity(int n) {
    SquareMatrix I(2);
    I[0][0] = I[1][1] = 1;
    I[0][1] = I[1][0] = 0;
    return I;
}

SquareMatrix pow(SquareMatrix& A, ll n) {
    if(n == 0)
        return identity(2);
    if(n % 2) 
        return pow(A, n-1) * A;
    SquareMatrix half = pow(A, n/2);
    return half * half;

}

ll solve(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    SquareMatrix mat(2);
    mat[0][0] = 1;
    mat[0][1] = mat[1][0] = 1;
    mat[1][1] = 0;
    SquareMatrix ret = pow(mat, n-1);
    return ret[0][0];
}

int main() {
    ll n; cin >> n;
    cout << solve(n) << "\n";
}
