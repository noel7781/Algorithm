#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<pair<string, int> > dict;
map<int, string> Idx2Word;


int main() {
    cin >> n;
    dict.assign(n, pair<string, int> ());
    for(int count = 0; count < n; ++count) {
        string str; cin >> str;
        Idx2Word[count] = str;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == 'n') {
                if(i+1 < str.size() && str[i+1] =='g') {
                    str[i] = 'o';
                    str.erase(i+1, 1);
                }
            } else if(str[i] >= 'o') {
                str[i] = str[i] + 1;
            } else if(str[i] == 'k') {
                str[i] = 'c';
            }
        }
        dict[count] = make_pair(str, count);
    }
    sort(dict.begin(), dict.end());
    for(int i = 0; i < n; ++i) {
        cout << Idx2Word[dict[i].second] << "\n";
    }
}
