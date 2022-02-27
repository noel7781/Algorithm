#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string string_add(string& a, string& b) {
    int carry = 0;
    int max_len = max(a.length(), b.length()) + 1;
    int alen = a.length(); int blen = b.length();
    if(alen == 0) return b;
    if(blen == 0) return a;
    string ret(max_len, '0');
    for(int i = 0; i < max_len - alen; i++) {
        a = "0" + a;
    }
    for(int i = 0; i < max_len - blen; i++) {
        b = "0" + b;
    }
    int zero_add = 0; 
    for(int i = max_len-1; i >= 0; i--) {
        int add_ret = a[i] - '0' + b[i] - '0' + carry;
        char num = (add_ret % 10) + '0';
        carry = add_ret / 10;
        ret[i] = num;
    }
    if(ret[0] == '0') ret = ret.substr(1);
    return ret;
}

string multiply_str(string& a, string& b) {
    string ret = "";
    int outer_zero_add = 0;
    for(int i = (int)a.size()-1; i >= 0; i--) {
        string tmp = "";
        int inner_zero_add = 0;
        for(int j = (int)b.size()-1; j >= 0; j--) {
            string mul_ret = to_string((a[i]-'0') * (b[j]-'0'));
            for(int k = 0; k < inner_zero_add; k++) {
                mul_ret += "0";
            }
            inner_zero_add++;
            tmp = string_add(tmp, mul_ret);
        }
        for(int k = 0; k < outer_zero_add; k++) {
            tmp += "0";
        }
        outer_zero_add++;
        ret = string_add(ret, tmp);
    }
    return ret;
}

int main() {
    string a; int b; cin >> a >> b;
    int after_count = 0;
    string no_point;
    bool is_begin = false;
    for(int i = 0; i < (int)a.size(); i++) {
        if(a[i] == '.') {
            is_begin= true;
            continue;
        }
        else if(is_begin) after_count++;
        no_point += a[i];
    }
    after_count *= b;
    string ret = no_point;
    for(int i = 0; i < b-1; i++) {
        ret = multiply_str(ret, no_point);
    }
    int total_len = ret.length();
    int point_place = total_len - after_count;
    ret.insert(point_place, ".");
    cout << ret << "\n";

}
