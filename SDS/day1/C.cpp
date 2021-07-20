#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<bool> > words;
map<int, char> word2Idx;

int getSubset(vector<int>& learn, int pos) {
    if(learn.size() == k) {
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            bool find = true;
            for(int j = 0; j < 21; ++j) {
                if(words[i][j] == 1) {
                    bool inner_find = false;
                    for(int m = 0; m < k; ++m) {
                        if(learn[m] == j) {
                            inner_find = true;
                            break;
                        }
                    }
                    if(!inner_find) {
                        find = false;        
                        break;
                    }
                }
            }
            if(find) {
                cnt += 1;
            }
        }
        return cnt;
    }
    int ret = 0;
    for(int i = pos; i < 21; ++i) {
        learn.push_back(i);
        ret = max(ret, getSubset(learn, i+1));
        learn.pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    words.assign(n, vector<bool>(21, 0));
    int start = 0;
    for(int i = 0; i < 26; ++i) {
        char c = i + 'a';
        if(c != 'a' && c != 'n' && c != 't' && c != 'i' && c !='c') {
            word2Idx[c] = start;
            start += 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        string word; cin >> word;
        for(int j = 0; j < word.size(); ++j) {
            char c = word[j];
            if(c != 'a' && c != 'n' && c != 't' && c != 'i' && c !='c')
                words[i][word2Idx[c]] = 1;
        }
    }
    int ret = 0;
    if(k >= 5) {
        k -= 5;
        vector<int> learn;
        ret = max(ret, getSubset(learn, 0));
    }
    cout << ret << "\n";
}