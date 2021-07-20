#include <iostream>
#include <map>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    string name;
    map<string, int> m;
    int sz = 0;
    while(getline(cin, name)) {
        if(m.find(name) == m.end()) {
            m.insert(make_pair(name, 1));
        } else {
            m[name]++;
        }
        sz += 1;
    }

    cout << fixed;
    cout.precision(4);
    for(auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << (double)it->second * 100 / sz  << endl;
    }

}