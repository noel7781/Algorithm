#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int l, c;

vector<char> v;

void printSubset(vector<char> subset, int pos) {
    if(subset.size() == l) {
        int vowel_cnt=  0;
        for(auto c: subset) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowel_cnt += 1;
            }
        }
        if(vowel_cnt < 1 || l-vowel_cnt < 2) {
            return;
        }
        for(auto c: subset) {
            printf("%c", c);
        }
        printf("\n");
        return;
    }
    for(int i = pos; i < c; ++i) {
        subset.push_back(v[i]);
        printSubset(subset, i+1);
        subset.pop_back();
    }
}

int main() {
    cin >> l >> c;
    v.assign(c, ' ');
    for(int i = 0; i < c; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<char> subset;
    printSubset(subset, 0);
}