#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int max_block = 1;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int> > moveBoard(vector<vector<int> >& board, int d) {
    vector<vector<int> > copy(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            copy[i][j] = board[i][j];
        }
    }
    if(d == 0) {
        for(int i = 0; i < n; ++i) {
            for(int j = n-1; j >= 0; --j) {
                bool success = false;
                if(copy[i][j] != 0) {
                    if(j == 0) continue;
                    for(int k = j-1; k >= 0; --k) {
                        if(copy[i][k] == copy[i][j]) {
                            copy[i][j] *= 2;
                            copy[i][k] = 0;
                            break;
                        } else if(copy[i][k] != 0) {
                            break;
                        }
                    }
                } else if(copy[i][j] == 0) {
                    for(int k = j; k >= 0; --k) {
                        if(copy[i][k] != 0) {
                            copy[i][j] = copy[i][k];
                            copy[i][k] = 0;
                            success = true;
                            break;
                        }
                    }
                }
                if(success) {
                    j += 1;
                }
            }
        }
    } else if(d == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                bool success = false;
                if(copy[i][j] != 0) {
                    if(j == n-1) continue;
                    for(int k = j+1; k < n; ++k) {
                        if(copy[i][k] == copy[i][j]) {
                            copy[i][j] *= 2;
                            copy[i][k] = 0;
                            break;
                        } else if(copy[i][k] != 0) {
                            break;
                        }
                    }
                } else if(copy[i][j] == 0) {
                    for(int k = j; k < n; ++k) {
                        if(copy[i][k] != 0) {
                            copy[i][j] = copy[i][k];
                            copy[i][k] = 0;
                            success = true;
                            break;
                        }
                    }
                }
                if(success) {
                    j -= 1;
                }
            }
        }
    } else if(d == 1) {
        for(int j = 0; j < n; ++j) {
            for(int i = n-1; i >= 0; --i) {
                bool success = false;
                if(copy[i][j] != 0) {
                    if(i == 0) continue;
                    for(int k = i-1; k >= 0; --k) {
                        if(copy[k][j] == copy[i][j]) {
                            copy[i][j] *= 2;
                            copy[k][j] = 0;
                            break;
                        } else if(copy[k][j] != 0) {
                            break;
                        }
                    }
                } else if(copy[i][j] == 0) {
                    for(int k = i; k >= 0; --k) {
                        if(copy[k][j] != 0) {
                            copy[i][j] = copy[k][j];
                            copy[k][j] = 0;
                            success = true;
                            break;
                        }
                    }
                }
                if(success) {
                    i += 1;
                }
            }
        }
    } else {
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < n; ++i) {
                bool success = false;
                if(copy[i][j] != 0) {
                    if(i == n-1) continue;
                    for(int k = i+1; k < n; ++k) {
                        if(copy[k][j] == copy[i][j]) {
                            copy[i][j] *= 2;
                            copy[k][j] = 0;
                            break;
                        } else if(copy[k][j] != 0) {
                            break;
                        }
                    }
                } else if(copy[i][j] == 0) {
                    for(int k = i; k < n; ++k) {
                        if(copy[k][j] != 0) {
                            copy[i][j] = copy[k][j];
                            copy[k][j] = 0;
                            success = true;
                            break;
                        }
                    }
                }
                if(success) {
                    i -= 1;
                }
            }
        }
    }
    return copy;
}


void solve(vector<vector<int> > board, int step) {
    if(step == 10) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] > max_block) {
                    max_block = board[i][j];
                }
            }
        }
        /*
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout<< "--------------------------------\n";
        */
        return;
    } else {
        for(int d = 0; d < 4; ++d) {
            vector<vector<int> > newBoard(n, vector<int>(n, 0));
            newBoard = moveBoard(board, d);
            solve(newBoard, step+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<vector<int> > board;
    board.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    solve(board, 0);

    cout << max_block << "\n";

}
