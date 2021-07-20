#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    vector<int> cnt(26, 0);
    string str; cin >> str;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] - 'a' < 0) {
            cnt[str[i] - 'A'] += 1;
        } else {
            cnt[str[i] - 'a'] += 1;
        }
    }
    int max_idx = -1;
    int max_val = -1;
    int max_cnt = 0;
    for(int i = 0; i < 26; ++i) {
        if(max_val < cnt[i]) {
            max_idx = i;
            max_cnt = 1;
            max_val = cnt[i];
        } else if(max_val == cnt[i]) {
            max_cnt += 1;
        }
    }
    char ret;
    if(max_cnt == 1) {
        ret = max_idx + 'A';
    } else {
        ret = '?';
    }
    cout << ret << "\n";
}
