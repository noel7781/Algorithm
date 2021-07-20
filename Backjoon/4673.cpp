#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool selfNumber[10001];

int self(int k) {
    string str = to_string(k);
    int sum = 0;
    for(int i = 0; i < str.size(); ++i) {
        sum += (str[i] - '0');
    }
    return k+sum;
}

void calcSelf() {
    memset(selfNumber, 1, sizeof(selfNumber));
    for(int i = 1; i <= 10000; ++i) {
        if(selfNumber[i]) {
            int k = i;
            while(k <= 10000) {
                k = self(k);
                selfNumber[k] = 0;
            }
        }
    }
}

int main() {
    calcSelf();
    for(int i = 1; i <= 10000; ++i) {
        if(selfNumber[i]) cout << i << "\n";
    }

}
