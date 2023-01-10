#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, int> pos = {{"black",0},{"brown",1},{"red",2}
,{"orange",3}, {"yellow", 4},{"green", 5},{"blue", 6}, {"violet",7},{"grey", 8}, {"white", 9}};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b, c; cin >> a >> b >> c;
    ll ret = 0;
    ret += pos[a];
    ret *= 10;
    ret += pos[b];
    ret *= pow(10, pos[c]);
    cout << ret << "\n";
}