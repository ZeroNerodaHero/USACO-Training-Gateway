/*
ID: billyz43
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
#define INF 9999
std::ifstream in("leap2.in");
std::ofstream out("leap2.out");
using namespace std;
int N;
int ar[368][368];
int dx[] = {-2, -2, -1, -1, 1,  1,  2, 2};
int dy[] = {-1,  1,  2, -2, 2, -2, -1, 1};
bool v[368][368];
int p[1000];
int ans[1000], len;

bool cmp(){
    for(int i = 0; i <= len; i++){
        if(p[i] < ans[i]) return true;
        if(p[i] > ans[i]) return false;
    }
    return false;
}

void dfs(int i, int j, int d){
    v[i][j] = true;
    p[d] = ar[i][j];
    for(int k = 0; k < 8; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx <= 0 || nx > N || ny <= 0 || ny > N || v[nx][ny]){ 
            continue;
        }

        if(ar[nx][ny] > ar[i][j]){
            dfs(nx,ny,d+1);
        }
    }

    if(d > len || (d == len && cmp())){
        for(int i = 0; i <= d; i++){
            ans[i] = p[i];
        }
        len = d;
    }
    v[i][j] = false;
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            in >> ar[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dfs(i,j,0);
        }
    }
    len++;
    cout << len << endl;
    for(int i = 0; i < len; i++){
        cout << ans[i] << endl;
    }
}
