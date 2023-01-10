#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* children[10];
    bool terminal;
    Trie() {
        for (int i = 0; i < 10; i++) {
            children[i] = NULL;
            terminal = false;
        }
    }
    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (children[i] != NULL) {
                delete children[i];
            }
        }
    }
    void insert(string s) {
        Trie* cur = this;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - '0';
            if (cur->children[idx] == NULL) {
                cur->children[idx] = new Trie();
            }
            cur = cur->children[idx];
        }
        cur->terminal = true;
    }
    bool find(string s) {
        Trie* cur = this;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - '0';
            if (cur->children[idx] == NULL) {
                return false;
            }
            cur = cur->children[idx];
            if(cur->terminal) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        Trie* t = new Trie();
        bool is_fail = false;
        vector<string> vs(N);
        for(int i = 0; i < N; i++) {
            string s; cin >> s;
            vs[i] = s;
        }
        sort(vs.begin(), vs.end());
        for(int i = 0; i < N; i++ ) {
            if(t->find(vs[i])) {
                is_fail = true;
                break;
            } 
            t->insert(vs[i]);
        }
        
        if(is_fail) cout << "NO\n";
        else cout << "YES\n";

        delete t;
        
    }
}