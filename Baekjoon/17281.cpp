#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > V;
int getScore(vector<int>& orders) {
    int ret = 0;
    swap(orders[0], orders[3]);

    int out_count = 0;
    int acc = 0;
    int last_idx = 0;
    for(int inning = 0; inning < N; inning++) { 
        vector<int> exists(4, 0);
        out_count = 0;
        while(out_count < 3) {
            for(int j = 0; j < 9; j++) {
                int result = V[inning][orders[(last_idx+j)%9]];
                if(result == 0) {
                    out_count++;
                    if(out_count == 3) {
                        last_idx = (last_idx+j+1)%9;
                        break;
                    }
                } else if(result == 1) {
                    if(exists[3]) {
                        exists[3] = 0;
                        ret++;
                    }
                    if(exists[2]) {
                        exists[3] = 1;
                        exists[2] = 0;
                    }
                    if(exists[1]) {
                        exists[2] = 1;
                        exists[1] = 0;
                    }
                    exists[1] = 1;
                } else if(result == 2) {
                    if(exists[3]) {
                        exists[3] = 0;
                        ret++;
                    }
                    if(exists[2]) {
                        exists[2] = 0;
                        ret++;
                    }
                    if(exists[1]) {
                        exists[3] = 1;
                        exists[1] = 0;
                    }
                    exists[2] = 1;

                } else if(result == 3) {
                    if(exists[3]) {
                        exists[3] = 0;
                        ret++;
                    }
                    if(exists[2]) {
                        exists[2] = 0;
                        ret++;
                    }
                    if(exists[1]) {
                        exists[1] = 0;
                        ret++;
                    }
                    exists[3] = 1;
                } else if(result == 4) {
                    for(int k = 1; k <= 3; k++) {
                        ret += exists[k];
                        exists[k] = 0;
                    }
                    ret++;
                }
            }
        }
    }

    swap(orders[0], orders[3]);
    return ret;
}
int search(vector<int>& orders, int use) {
    int ret = 0;
    if(use == (1 << 9) - 1) {
        return getScore(orders);
    } else {
        for(int j = 1; j < 9; j++) {
            if(use & (1 << j)) continue;
            orders.push_back(j);
            ret = max(ret, search(orders, use | (1 << j)));
            orders.pop_back();
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    V.resize(N, vector<int>(9, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> V[i][j];
        }
    }
    vector<int> orders;
    orders.push_back(0);
    int ret = 0;

    ret = max(ret, search(orders, 1));
    cout << ret << "\n";
    return 0;
}