#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N, M;
vector<vi> cost;
int Q;
int Y, X, R, C, K, D;

int dX[4] = {0, 0, 1,- 1 };
int dY[4] = {-1, 1, 0, 0 };


struct segTree {
    int n;
    vector<int> rangeMax;

    segTree(const vector<vi>& array) {
        rangeMax.resize(N*M*4*4);
        init(array, 0, M-1, 0, N-1, 0);
    }
    int init(const vector<vi>& array, int left, int right, int top, int bottom, int node) {
        if(left > right || top > bottom) return 0;
        if(left == right && top == bottom) {
            return rangeMax[node] = array[top][left];
        }
        int midY = (top + bottom) / 2;
        int midX = (left + right) / 2;
        int left_up_Max = init(array, left, midX, top, midY, node*4+1);
        int right_up_Max = init(array, midX+1, right, top, midY, node*4+2);
        int left_down_Max = init(array, left, midX, midY+1, bottom, node*4+3);
        int right_down_Max = init(array, midX+1, right, midY+1, bottom, node*4+4);

        return rangeMax[node] = max(max(left_up_Max, left_down_Max), max(right_up_Max, right_down_Max));
    }
    int query(int left, int right, int top, int bottom, int node, int nodeLeft, int nodeRight, int nodeTop, int nodeBottom) {
        if(nodeLeft > nodeRight || nodeTop > nodeBottom || right < nodeLeft || nodeRight < left || bottom < nodeTop || nodeBottom < top)
            return -1;
        if(left <= nodeLeft && nodeRight <= right && top <= nodeTop && nodeBottom <= bottom) {
            return rangeMax[node];
        }
        int midY = (nodeTop + nodeBottom) / 2;
        int midX = (nodeLeft + nodeRight) / 2;
        return max(max(query(left, right, top, bottom, node*4 + 1, nodeLeft, midX, nodeTop, midY), 
                       query(left, right, top, bottom, node*4 + 3, nodeLeft, midX, midY+1, nodeBottom)),
                   max(query(left, right, top, bottom, node*4 + 2, midX+1, nodeRight, nodeTop, midY),
                       query(left, right, top, bottom, node*4 + 4, midX+1, nodeRight, midY+1, nodeBottom)));
    }
    int query(int left, int right, int top, int bottom) {
        if(left > right) swap(left, right);
        if(top > bottom) swap(top, bottom);
        return query(left, right, top, bottom, 0, 0, M-1, 0, N-1);
    }
};

int solve(struct segTree& t) {
    int dy = dY[D], dx = dX[D];
    int res = 0;
    if(D == 0 || D == 1) {
        for(int i = 0; i < K; ++i) {
            int x1 = X;
            int x2 = X + (C - 1);
            int a = Y + i*dy + N;
            int b = Y + (R-1) + i*dy + N;
            if(a >=N) a %= N;
            if(b >= N) b %= N;
            // printf("query parameter x1 %d x2 %d a %d b %d\n", x1,x2,a,b);
            int tmp = t.query(x1, x2, a, b);
            // cout << "query return: " << tmp << endl;
            res ^= tmp;
        }
    } else if (D == 2 || D == 3) {
        for(int i = 0; i < K; ++i) {
            int a = X + i*dx;
            int b = X + (C-1) + i*dx;
            int y1 = Y;
            int y2 = Y + (R - 1);
            if(a >=M) a %= M;
            if(b >= M) b %= M;
            // printf("query parameter a %d b %d y1 %d y2 %d\n", a,b,y1,y2);
            int tmp = t.query(a, b, y1, y2);
            // cout << "query return: " << tmp << endl;
            res ^= tmp;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cost.assign(N, vector<int> (M, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> cost[i][j];
        }
    } 
    struct segTree t = segTree(cost);
    cin >> Q;
    while(Q--) {
        cin >> Y >> X >> R >> C >> K >> D;
        Y -= 1;
        X -= 1;
        D -= 1;
        cout << solve(t) << "\n";
    }
}
