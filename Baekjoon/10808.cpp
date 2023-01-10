#include <iostream>

using namespace std;

int alpha[27];

int main() {
    string str; cin >> str;
    for(int i = 0; i < str.size(); ++i) {
        alpha[str[i]-'a']++;
    }
    for(int i = 0; i < 26; ++i) {
        cout << alpha[i] << " ";
    }
    cout << "\n";
}
