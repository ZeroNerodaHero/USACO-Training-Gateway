/*
ID: billy
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

int dfs(int x,int y, int x1, int y1, int cl){
    if(dp[x][y][x1][y1][cl] > 0) return dp[x][y][x1][y1][cl];
    if(cl == 0){
//cout << '\t' << x << ' ' << y << ' ' << x1 << ' ' << y1 << ": " << ar[x][y] << ' ' << ar[x1][y1] << endl;
        return 1;
    }
    //if((cl != L-1) && (x == x1 && y == y1)) return 0;
//cout << "cur: " << cl << ' ' << x << ' ' << y << ' ' << x1 << ' ' << y1 << endl;

    int ans = 0;
    cl-=2;

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i]; 
        int ny = y + dy[i]; 
        if(nx < 0 || nx >= N ||
           ny < 0 || ny >= N){
            continue;
        }

        for(int j = 0; j < 8; j++){
            int nx1 = x1 + dx[j];
            int ny1 = y1 + dy[j];
            if(nx1 < 0 || nx1 >= N ||
               ny1 < 0 || ny1 >= N){
                continue;
            }

            if(ar[nx][ny] == ar[nx1][ny1]){
                ans += dfs(nx,ny,nx1,ny1,cl);
            }
        }
    }
    dp[x][y][x1][y1][cl] = ans;
    dp[x1][y1][x][y][cl] = ans;
    return ans;
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
    int ans = 0;
    if(L&1){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                memset(dp,0,sizeof(dp));
                ans += dfs(i,j,i,j,L-1);
cout << "ans " << ans << endl;
            }
        }
    } else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k <8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < N &&
                       ny >= 0 && ny < N &&
                       ar[i][j] == ar[nx][ny]){
                       memset(dp,0,sizeof(dp));
                        ans += dfs(i,j,nx,ny,L-2);
cout << "ans " << ans << endl;
                    }
                }
            }
        }

    }
    out << ans << endl;
}
