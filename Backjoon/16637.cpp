#include <bits/stdc++.h>
using namespace std;
int N;
vector<char> V;

int calculation(int left, int right, char ops) {
    int ret = 0;
    switch(ops) {
        case '+':
            ret = left + right;
            break;
        case '-':
            ret = left - right;
            break;
        case '*':
            ret = left * right;
            break;
        default:
            break;
    }
    return ret;
}

int solve(int parenthesis) {
    stack<int> s_num;
    stack<char> s_ops;
    s_num.push(V[0] - '0');
    for(int i = 1; i < N; i+=2) {
        int op_pos = i/2;
        if(parenthesis & (1 << op_pos)) {
            int num = s_num.top(); s_num.pop();
            int calc = calculation(num, V[i+1]-'0', V[i]);
            s_num.push(calc);
            if(!s_ops.empty()) {
                int a = s_num.top(); s_num.pop();
                int b = s_num.top(); s_num.pop();
                char op = s_ops.top(); s_ops.pop();
                int tmp = calculation(b, a, op);
                s_num.push(tmp); 
            }
        } else if(parenthesis & (1 << (op_pos+1))) {
            s_ops.push(V[i]);
            s_num.push(V[i+1]-'0');
        } else {
            int num = s_num.top(); s_num.pop();
            int calc = calculation(num, V[i+1]-'0', V[i]);
            s_num.push(calc);
        }
    }
    return s_num.top();
}


int search(int pos, int parenthesis) {
    if(pos == N/2) {
        return solve(parenthesis);
    }
    int ret = -1e9;
    if(pos == 0) {
        ret = search(pos+1, parenthesis);
        ret = max(ret, search(pos+1, parenthesis | (1 << pos)));
    } else {
        if(!(parenthesis & (1 << (pos-1)))) {
            ret = max(ret, search(pos+1, parenthesis | (1 << pos)));
        }
        ret = max(ret, search(pos+1, parenthesis));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; V.resize(N);
    for(auto &it: V) cin >> it;
    cout << search(0, 0) << "\n";
}