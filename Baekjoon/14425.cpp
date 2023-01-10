#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie* child[26];
    bool terminal;
    Trie(): terminal(false) {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }

    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(child[i]) delete (child[i]);
        }
    }

    void insert(const char* k) {
        if(*k == '\0') {
            terminal = true;
            return;
        }
        int idx = *k - 'a';
        if(!child[idx]) child[idx] = new Trie();
        child[idx]->insert(k+1);
    }

    Trie* find(const char* k) {
        if(*k == '\0') return this;
        int idx = *k - 'a';
        if(!child[idx]) return NULL;
        return child[idx]->find(k+1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    Trie* t = new Trie();
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        t->insert(s.c_str());
    }
    int ret = 0;
    for(int i = 0; i < M; i++) {
        string s; cin >> s;
        Trie * cur = t->find(s.c_str());
        if(cur && cur->terminal) {
            ret++;
        }
    }
    cout << ret << "\n";
    delete t;
}