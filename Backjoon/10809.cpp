#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    vector<int> idx(26, -1);
    string str; cin >> str;
    for(int i = 0; i < str.size(); ++i) {
        if(idx[str[i] - 'a'] == -1) {
            idx[str[i] - 'a'] = i;
        }
    }
    for(int i = 0; i < 26; ++i) {
        cout << idx[i] << " ";
    }
}
