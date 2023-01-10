#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int a, b;
int n, m;
// Direction: N->0 E->1 S->2 W->3
// robot d: L->-1 | R->1 | F-> 0
void solve(vector<iii> robots, vector<iii> commands) {

}

int main() {
    cin >> a >> b;
    cin >> n >> m;
    vector<tuple<int, int, int> > robots(n);
    for(int i = 0; i < n; ++i) {
        char d_c; int x, y, d; cin >> x >> y >> d_c;
        if(d_c == 'N') d = 0;
        else if(d_c == 'E') d = 1;
        else if(d_c == 'S') d = 2;
        else d = 3;
        robots[i] = make_tuple(x, y, d);
    }
    vector<tuple<int, int, int> > commands(m);
    for(int i = 0; i < m; ++i) {
        int k, o, l; char o_c; cin >> k >> o_c >> l;
        if(o_c == 'L') o = -1;
        else if(o_c == 'R') o = 1;
        else o = 0;
        commands[i] = make_tuple(k, o, l);
    }
    solve(robots, commands);
}
