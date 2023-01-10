#include <bits/stdc++.h>
using namespace std;
int P, B;

map<int, string> mapper = {
    {0, "0"},
    {1, "1"},
    {2, "2"},
    {3, "3"},
    {4, "4"},
    {5, "5"},
    {6, "6"},
    {7, "7"},
    {8, "8"},
    {9, "9"},
    {10, "A"},
    {11, "B"},
    {12, "C"},
    {13, "D"},
    {14, "E"},
    {15, "F"}
};

int get_repeat(string& input, int pos) {
    int ret = 0;
    while(pos < B-1) {
        if(input[pos*2] == input[pos*2+2] && input[pos*2+1] == input[pos*2+3]) {
            ret++;
            pos++;
        } else {
            break;
        }
    }
    return ret+1;
}

string encode(int num, int type) {
    int upper = num / 16;
    int lower = num % 16;
    if(type == 0) upper |= (1 << 3);
    return mapper[upper] + mapper[lower];
}

string solve(string& input, int pos) {
    if(pos >= B) return "";
    string ret = "";
    int count = 0;
    int repeat = 0;
    int mark = 0;
    for(int i = pos; i < B; i++) {
        repeat = get_repeat(input, i);
        if(repeat >= 3) {
            mark = i;
            break;
        } else {
            count++;
        }
    }
    int save_repeat = repeat;
    if(count >= 128) {
        ret += encode(127, 1);
        ret += input.substr(pos*2, 2*128);
        return ret + solve(input, pos + 128);
    }
    if(count > 0) {
        count -= 1;
        ret += encode(count, 1);
        ret += input.substr(pos*2, 2*(count+1));
    }
    if(repeat >= 130) {
        for(int k = 0; k <= (repeat/130)-1; k++) {
            ret += "FF";
            ret += input.substr(mark*2, 2);
        }
        repeat %= 130;
        return ret + solve(input, mark + (save_repeat / 130 * 130));
    }
    if(repeat >= 3) {
        ret += encode(repeat-3, 0);
        ret += input.substr(mark*2, 2);
    }
    if(repeat == 1) {
        return ret;
    }
    return ret + solve(input, mark + save_repeat);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> P;
    for(int t = 0; t < P; t++) {
        cin >> B;
        int input_count = (B * 2) / 80 + !!((B * 2) % 80);
        string input = "";
        string tmp;
        for(int tt = 0; tt < input_count; tt++) {
            cin >> tmp;
            input += tmp;
        }
        string ret = solve(input, 0);
        int len = ret.length();
        cout << len / 2 << "\n";
        int last = len % 80;
        for(int i = 0; len > 0; len -= 80, i += 80) {
            cout << ret.substr(i, min(len, 80)) << "\n";
        }
    }
}