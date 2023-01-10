#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> q;
    int n; cin >> n;
    for(int i = n; i >= 1; --i) {
        q.push_back(i);
    }
    while(q.size() != 1) {
        q.pop_back();
        int x = q.back();
        q.pop_back();
        q.push_front(x);
    }
    cout << q.front() << "\n";
}
