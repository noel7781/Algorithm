#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t;
int n, d, p;
int connected[51][51];
int c_t, q;

double cache[51][101];

double solve(int idx, int days) {
    //cout << "idx: "<<idx<< " and days: "<<days<<endl;
    if(days == d && idx == q) {
        return 1.0;
    } else if(days == d) {
        return 0.0;
    }
    double& ret = cache[idx][days];
    if(ret != -1.0)
        return ret;
    ret = 0;
    int adj_cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(connected[idx][i] == 1) {
            adj_cnt += 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(connected[idx][i] == 1) {
            ret += solve(i, days+1) / adj_cnt; 
        }
    }
    return ret;
}

int main() {
    cin >> t;
    while(t--) {
        memset(connected, 0, sizeof(connected));
        for(int i = 0; i < 51; ++i) {
            for(int j = 0; j < 101; ++j) {
                cache[i][j] = -1.0;
            }
        }
        cin >> n >> d >> p;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> connected[i][j];
            }
        }
        cin >> c_t;
        while(c_t--) {
            for(int i = 0; i < 51; ++i) {
                for(int j = 0; j < 101; ++j) {
                    cache[i][j] = -1.0;
                }
            }
            cin >> q;
            //printf("%d ", solve(q, 0));
            printf("%.9f ", solve(p, 0));
        }
        printf("\n");
    }
}
