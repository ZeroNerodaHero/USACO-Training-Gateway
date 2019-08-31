/*
ID: billy
PROG: leap2
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
#define INF 160000
std::ifstream in("leap2.in");
std::ofstream out("leap2.out");
using namespace std;
int N;
int ar[368][368];
int dx[] = {-2, -2, -1, -1, 1,  1,  2, 2};
int dy[] = {-1,  1,  2, -2, 2, -2, -1, 1};
bool v[368][368];
int p[1000];
int dp[368][368], len;

int dfs(int i, int j){
    if(dp[i][j] > 0) return dp[i][j];
    v[i][j] = true;
    //p[d] = ar[i][j];
    int ans = 0;
    for(int k = 0; k < 8; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx <= 0 || nx > N || ny <= 0 || ny > N || v[nx][ny]){ 
            continue;
        }

        if(ar[nx][ny] > ar[i][j]){
            ans = max(ans,dfs(nx,ny));
        }
    }
    v[i][j] = false;
    dp[i][j] = ans+1;
    return ans+1;
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            in >> ar[i][j];
        }
    }
    int x, y;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int l = dfs(i,j);
            if(ans < l || (ans == l && ar[i][j] < ar[x][y])){
                ans = max(ans,l);
                x = i;
                y = j;
            }
        }
    }
    out << ans << endl;
    for(int i = ans; i > 0; i--){
        out << ar[x][y] << endl;
        int best = INF;
        int nnx,nny;
        for(int j = 0; j < 8; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx > 0 && nx <= N &&
               ny > 0 && ny <= N &&
               dp[nx][ny] == i-1 && 
               ar[nx][ny] < best){
                nnx = nx;
                nny = ny;
                best = ar[nx][ny];
            } 
        }
        x = nnx;
        y = nny;
    }
}
