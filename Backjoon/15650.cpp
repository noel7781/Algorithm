#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> permutation;
vector<bool> chosen;

void solve(int pos) {
    if(permutation.size() == M) {
        for(auto x: permutation) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        for(int i = pos+1; i <= N; ++i) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            solve(i);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    chosen.reserve(N+1);
    solve(0);
}