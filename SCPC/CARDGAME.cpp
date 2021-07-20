#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int X[3002];
int Y[3002];
int ret = 0;
int dp[3002][3002];


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        cin >> n >> k;
        ret = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> X[i];
        }
        for(int i = 1; i <= n; ++i) {
            cin >> Y[i];
        }
        dp[0][0] = 1; dp[1][0] = 0; dp[0][1] = 0; dp[1][1] = 1;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                
            }
        }
		cout << "Case #" << test_case+1 << endl;
        cout << ret << " " << (n+1)*(n+1) - ret << "\n";
	}

	return 0;
}
