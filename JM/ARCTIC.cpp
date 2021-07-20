#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;

double dist[101][101];

void calcDistance(vector<pdd>& coord, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            dist[i][j] = sqrt((coord[i].first - coord[j].first) * (coord[i].first - coord[j].first) + \
                         (coord[i].second - coord[j].second) * (coord[i].second - coord[j].second));
        }
    }
}

bool connected(int pos, vector<bool>& visit, double gap) {
    visit[pos] = true;
    for(int i = 0; i < visit.size(); ++i) {
        if(!visit[i] && dist[pos][i] <= gap) {
            connected(i, visit, gap);
        }
    }

    for(int i = 0; i < visit.size(); ++i) {
        if(visit[i] == false) return false;
    }
    return true;

}

double solve(vector<pdd>& coord, int n) {
    double lo = 0.0, hi = 1500;
    for(int i = 0; i < 100; ++i) {
        double mid = (lo + hi) / 2;
        vector<bool> visit(n, false);
        if(connected(0, visit, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 101; ++i) {
            for(int j = 0; j < 101; ++j) {
                dist[i][j] = 0.0;
            }
        }
        int n; scanf("%d", &n);
        vector<pdd> coord(n);
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &coord[i].first, &coord[i].second);
        }
        calcDistance(coord, n);
        printf("%.2f\n", solve(coord, n));
    }
}
