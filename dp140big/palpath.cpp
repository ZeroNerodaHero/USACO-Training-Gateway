/*
ID: billyz43
PROG: palpath
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("palpath.in");
std::ofstream out("palpath.out");
using namespace std;
int N,L;
int ar[20][20];
int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};
int dp[20][20][20][20][17];
int adjx[20][20][8];
int adjy[20][20][8];
int deg[20][20];

int main(){
    in >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> ar[i][j];
            for(int k = 0; k < 8; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < N &&
                   nj >= 0 && nj < N){
                        adjx[i][j][deg[i][j]] = ni;
                        adjy[i][j][deg[i][j]] = nj;
                        deg[i][j]++;
                }
                dp[i][j][i][j][1] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < deg[i][j]; k++){
                int &x = adjx[i][j][k];
                int &y = adjy[i][j][k];
        
                if(ar[x][y] == ar[i][j]){
                    dp[i][j][x][y][2] = 1;
                }
            }
        }
    }
    int a = 0, b = 1, c = 2;
    if(L == 1){
        c = 1;
    }
    for(int l = 3; l <= L; l++){
        a = (a+1)%3;
        b = (b+1)%3;
        c = (c+1)%3;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int x = 0; x < N; x++){
                    for(int y = 0; y < N; y++){
                        dp[i][j][x][y][c] = 0;
                    }   
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int x = 0; x < N; x++){
                    for(int y = 0; y < N; y++){
                        if(ar[i][j] != ar[x][y]){
                            continue;
                        }
                        for(int k = 0; k < deg[i][j]; k++){
                            int &ni = adjx[i][j][k];
                            int &nj = adjy[i][j][k];
                            for(int o = 0; o < deg[x][y]; o++){
                                int &nx = adjx[x][y][o];
                                int &ny = adjy[x][y][o];
                                               
                                dp[i][j][x][y][c] += dp[ni][nj][nx][ny][a];
//cout << '\t' << ni << ' ' << nj << ' '<< nx << ' '<< ny <<' ' << dp[ni][nj][nx][ny][a] << endl;
                            }
                        }
//cout << i << ' ' << j << ' '<< x << ' '<< y <<' ' << dp[i][j][x][y][c] << endl;
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    ans += dp[i][j][x][y][c];
//cout << "\tans " <<  ans << endl;
                }
            }
        }
    }
    out << ans << endl;
}
