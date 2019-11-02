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

void dfs(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j][i][j][0] = 1;
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    if(ar[x][y] == ar[i][j]) 
                        dp[i][j][x][y][2] = 1;
                }
            }
        }
    }
    for(int len = 4; len <= L; len+=2){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int x = 0; x < N; x++){
                for(int y = 0; y < N; y++){
                    if(ar[x][y] == ar[i][j]){
                        
                        for(int k = 0; k < 8; k++){
                            int ni = i+dx[k];
                            int nj = j+dy[k];

                            if(ni < 0 || ni >= N ||
                               nj < 0 || nj >= N){
                                continue;
                            }

                            for(int l = 0; l < 8; l++){
                                int nx = x+dx[l];
                                int ny = y+dy[l];
                            
                                if(nx < 0 || nx >= N ||
                                   ny < 0 || ny >= N){
                                    continue;
                                }

                                if(ar[ni][nj] == ar[nx][ny]){
                                    dp[i][j][x][y][len] += dp[ni][nj][nx][ny][len-2];
//cout << "added " << dp[i][j][x][y][len] << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    }
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout <<  ar[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    in >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> ar[i][j];
        }
    }
//    print();
    long long ans = 0;
    dfs();
    if(L == 1){
        ans = N*N;
    } else if(L&1){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
//cout << i <<" " << j << endl;
                for(int k = 0; k <8; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni < 0 || ni >= N ||
                       nj < 0 || nj >= N){
                            continue;
                    }

                    for(int l = 0; l < 8; l++){
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if(nx >= 0 && nx < N &&
                           ny >= 0 && ny < N &&
                           ar[ni][nj] == ar[nx][ny]){
                            ans += dp[ni][nj][nx][ny][L-1];               
//cout <<"\t" << ni << ' '<< nj << ' ' << nx << ' ' << ny << ' ' <<  dp[ni][nj][nx][ny][L-1];
//cout <<" ans " << ans << endl; 
                        }
                    }    
                }
            }
        }
cout << "ans " << ans << endl;
    } else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k <8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < N &&
                       ny >= 0 && ny < N &&
                       ar[i][j] == ar[nx][ny]){
                        ans += dp[i][j][nx][ny][L];
//cout << "ans " << ans << endl;
                    }
                }
            }
        }

    }
    out << ans << endl;
}
