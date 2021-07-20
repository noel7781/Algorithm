#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int N;
ll B;
vector<vector<int> > tmp;

vector<vector<int> > mat_mul(vector<vector<int> >& A, vector<vector<int> >& B) {
    tmp.assign(N, vector<int>(N, 0));
    for(int p = 0; p < N; ++p) {
        for(int q = 0; q < N; ++q) {
            int sum = 0;
            for(int r = 0; r < N; ++r) {
                sum += A[p][r] * B[r][q];
                sum %= 1000;
            }
            tmp[p][q] = sum;
        }
    }
    return tmp;
}

vector<vector<int> > solve(vector<vector<int> >& m, ll B) {
    if(B == 1) {
        return m;
    }
    vector<vector<int> > half = solve(m, B/2);
    vector<vector<int> > ret = mat_mul(half, half);
    if(B % 2) {
        return mat_mul(m, ret);        
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> B;
    vector<vector<int> > m;
    m.assign(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }
    vector<vector<int> > res;
    res.assign(N, vector<int>(N, 0));
    res = solve(m, B);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << res[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}