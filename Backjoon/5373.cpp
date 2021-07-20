#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char colors[7] = "wrbogy";
int n;

// d == 0 -> counterclockwise
// d == 1 -> clockwise
void rotate_mainPlane(vector<vector<char> >& cube, int n, int d) {
    vector<int> v1{0, 2, 8, 6};
    vector<int> v2{1, 5, 7, 3};
    if(d == 0) {
        char s1 = cube[n][v1[0]];
        char s2 = cube[n][v2[0]];
        for(int i = 0; i < 3; ++i) {
            cube[n][v1[i]] = cube[n][v1[i+1]];
            cube[n][v2[i]] = cube[n][v2[i+1]];
        }
        cube[n][v1[3]] = s1;
        cube[n][v2[3]] = s2;
    } else {
        char s1 = cube[n][v1[3]];
        char s2 = cube[n][v2[3]];
        for(int i = 2; i >= 0; --i) {
            cube[n][v1[i+1]] = cube[n][v1[i]];
            cube[n][v2[i+1]] = cube[n][v2[i]];
        }
        cube[n][v1[0]] = s1;
        cube[n][v2[0]] = s2;
    }
}

// cmd[1] == '-' -> counterclockwise
// cmd[1] == '+' -> clockwise
//
void rotate(vector<vector<char> >& cube, string cmd) {
    vector<vector<int> > mainPlane{ {0, 1, 2 }, { 2, 5, 8 }, { 8, 7, 6 }, { 6, 3, 0 } };
    if(cmd[0] == 'U') {
        vector<int> plane{ 1, 2, 3, 4};
        vector<int> location{ 0, 1, 2 };
        if(cmd[1] == '-') {
            vector<char> save{ cube[plane[3]][location[0]], cube[plane[3]][location[1]], cube[plane[3]][location[2]] };
            for(int i = 2; i >= 0; --i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i+1]][location[j]] = cube[plane[i]][location[j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[0]][location[j]] = save[j];
            }
            rotate_mainPlane(cube, 0, 0);

        } else {
            vector<char> save{ cube[plane[0]][location[0]], cube[plane[0]][location[1]], cube[plane[0]][location[2]] };
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i]][location[j]] = cube[plane[i+1]][location[j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[3]][location[j]] = save[j];
            }
            rotate_mainPlane(cube, 0, 1);
        }
    } else if(cmd[0] == 'D') {
        vector<int> plane{ 1, 2, 3, 4 };
        vector<int> location{ 6, 7, 8 };
        if(cmd[1] == '-') {
            vector<char> save{ cube[plane[0]][location[0]], cube[plane[0]][location[1]], cube[plane[0]][location[2]] };
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i]][location[j]] = cube[plane[i+1]][location[j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[3]][location[j]] = save[j];
            }
            rotate_mainPlane(cube, 5, 1);
        } else {
            vector<char> save{ cube[plane[3]][location[0]], cube[plane[3]][location[1]], cube[plane[3]][location[2]] };
            for(int i = 2; i >= 0; --i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i+1]][location[j]] = cube[plane[i]][location[j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[0]][location[j]] = save[j];
            }
            rotate_mainPlane(cube, 5, 0);
        }

    } else if(cmd[0] == 'R') {
        vector<int> plane{ 0, 3, 5, 1 };
        vector<vector<int> > location{ { 2, 5, 8 }, { 6, 3, 0 }, { 8, 5, 2 }, { 2, 5, 8 } };
        if(cmd[1] == '-') {
            vector<char> save{ cube[plane[0]][location[0][0]], cube[plane[0]][location[0][1]], cube[plane[0]][location[0][2]] };
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i]][location[i][j]] = cube[plane[i+1]][location[i+1][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[3]][location[3][j]] = save[j];
            }
            rotate_mainPlane(cube, 2, 0);
        } else {
            vector<char> save{ cube[plane[3]][location[3][0]], cube[plane[3]][location[3][1]], cube[plane[3]][location[3][2]] };
            for(int i = 2; i >= 0; --i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i+1]][location[i+1][j]] = cube[plane[i]][location[i][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[0]][location[0][j]] = save[j];
            }
            rotate_mainPlane(cube, 2, 1);
        }
    } else if(cmd[0] == 'L') {
        vector<int> plane{ 0, 3, 5, 1 };
        vector<vector<int> > location{ { 0, 3, 6 }, { 8, 5, 2 }, { 6, 3, 0 }, { 0, 3, 6 } };
        if(cmd[1] == '-') {
            vector<char> save{ cube[plane[3]][location[3][0]], cube[plane[3]][location[3][1]], cube[plane[3]][location[3][2]] };
            for(int i = 2; i >= 0; --i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i+1]][location[i+1][j]] = cube[plane[i]][location[i][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[0]][location[0][j]] = save[j];
            }
            rotate_mainPlane(cube, 4, 0);
        } else {
            vector<char> save{ cube[plane[0]][location[0][0]], cube[plane[0]][location[0][1]], cube[plane[0]][location[0][2]] };
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i]][location[i][j]] = cube[plane[i+1]][location[i+1][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[3]][location[3][j]] = save[j];
            }
            rotate_mainPlane(cube, 4, 1);
        }
    } else if(cmd[0] == 'F') {
        vector<int> plane{ 0, 2, 5, 4 };
        vector<vector<int> > location{ { 6, 7, 8 }, { 0, 3, 6 }, { 8, 7, 6 }, { 8, 5, 2 } };
        if(cmd[1] == '-') {
            vector<char> save{ cube[plane[0]][location[0][0]], cube[plane[0]][location[0][1]], cube[plane[0]][location[0][2]] };
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i]][location[i][j]] = cube[plane[i+1]][location[i+1][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[3]][location[3][j]] = save[j];
            }
            rotate_mainPlane(cube, 1, 0);
        } else {
            vector<char> save{ cube[plane[3]][location[3][0]], cube[plane[3]][location[3][1]], cube[plane[3]][location[3][2]] };
            for(int i = 2; i >= 0; --i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i+1]][location[i+1][j]] = cube[plane[i]][location[i][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[0]][location[0][j]] = save[j];
            }
            rotate_mainPlane(cube, 1, 1);
        }
    } else if(cmd[0] == 'B') {
        vector<int> plane{ 0, 2, 5, 4 };
        vector<vector<int> > location{ { 0, 1, 2 }, { 2, 5, 8 }, { 2, 1, 0 }, { 6, 3, 0 } };
        if(cmd[1] == '-') {
            vector<char> save{ cube[plane[3]][location[3][0]], cube[plane[3]][location[3][1]], cube[plane[3]][location[3][2]] };
            for(int i = 2; i >= 0; --i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i+1]][location[i+1][j]] = cube[plane[i]][location[i][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[0]][location[0][j]] = save[j];
            }
            rotate_mainPlane(cube, 3, 0);
        } else {
            vector<char> save{ cube[plane[0]][location[0][0]], cube[plane[0]][location[0][1]], cube[plane[0]][location[0][2]] };
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    cube[plane[i]][location[i][j]] = cube[plane[i+1]][location[i+1][j]];
                }
            }
            for(int j = 0; j < 3; ++j) {
                cube[plane[3]][location[3][j]] = save[j];
            }
            rotate_mainPlane(cube, 3, 1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        vector<vector<char> > cube(6, vector<char>(9, 0));
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 9; ++j) {
                cube[i][j] = colors[i];
            }
        }
        cin >> n; string cmd;
        for(int i = 0; i < n; ++i) {
            cin >> cmd;
            rotate(cube, cmd);
        }
   //     cout<<"윗면\n";
        for(int i = 0; i < 9; ++i) {
            cout << cube[0][i];
            if(i % 3 == 2) cout << "\n";
        }
        /*
        cout<<"앞면\n";
        for(int i = 0; i < 9; ++i) {
            cout << cube[1][i];
            if(i % 3 == 2) cout << "\n";
        }
        cout<<"오른쪽면\n";
        for(int i = 0; i < 9; ++i) {
            cout << cube[2][i];
            if(i % 3 == 2) cout << "\n";
        }
        cout<<"뒷면\n";
        for(int i = 0; i < 3; ++i) {
            cout << cube[3][2-i];
            if(i % 3 == 2) cout << "\n";
        }
        for(int i = 0; i < 3; ++i) {
            cout << cube[3][5-i];
            if(i % 3 == 2) cout << "\n";
        }
        for(int i = 0; i < 3; ++i) {
            cout << cube[3][8-i];
            if(i % 3 == 2) cout << "\n";
        }
        cout<<"왼쪽면\n";
        for(int i = 0; i < 3; ++i) {
            cout << cube[4][2-i];
            if(i % 3 == 2) cout << "\n";
        }
        for(int i = 0; i < 3; ++i) {
            cout << cube[4][5-i];
            if(i % 3 == 2) cout << "\n";
        }
        for(int i = 0; i < 3; ++i) {
            cout << cube[4][8-i];
            if(i % 3 == 2) cout << "\n";
        }
        cout<<"아래면\n";
        for(int i = 0; i < 9; ++i) {
            cout << cube[5][i];
            if(i % 3 == 2) cout << "\n";
        }
        cout<<"--------------\n";
        */
    }
}
