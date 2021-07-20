#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 1 오른 0 아래
int dX[] = {0, 1}; int dY[] = {1, 0};

int h, w, n;
vector<vector<int> > intersection;
int d[1002][1002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w >> n;    
    intersection.assign(h, vector<int>(w, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> intersection[i][j];
        }
    }
    d[0][0] = n-1;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            d[i+1][j] += d[i][j] / 2;
            d[i][j+1] += d[i][j] / 2;
            if(d[i][j] % 2 == 1) {
                if(intersection[i][j] == 1) {
                    d[i][j+1]++;
                } else {
                    d[i+1][j]++;
                }
            }
        }
    }
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            intersection[i][j] += d[i][j];
            intersection[i][j] %= 2;
        }
    }


    int ypos = 0, xpos = 0;
    while(ypos < h && xpos < w) {
        int mark = intersection[ypos][xpos];
        ypos += dY[mark];
        xpos += dX[mark];
    }
    cout << ypos+1 << " " << xpos+1 << "\n";
}