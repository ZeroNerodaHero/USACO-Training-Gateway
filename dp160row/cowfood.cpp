/*
ID: billy
PROG: cowfood
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
#define INF (1<<28)
std::ifstream in("cowfood.in");
std::ofstream out("cowfood.out");
using namespace std;
bool m[14][14];
bool v[14][14];
int N,M;

int dfs(int x, int y){
    if(y > N){
        if(x == M) return 1;
        y = 1;
        x++;
    }

    int ans = dfs(x,y+1);
    if(m[x][y] && !v[x][y-1] && !v[x-1][y]){
        v[x][y] = true;
        ans += dfs(x,y+1);
        v[x][y] = false;
    }
    return ans;
}


int main(){
    in >> M >> N;

    for(int  i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            in >> m[i][j];
        } 
    }
    int ans = dfs(1,1);
    out << ans << endl;
}
