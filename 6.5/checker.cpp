/*
ID: billyz43
PROG: checker
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
std::ifstream in("checker.in");
std::ofstream out("checker.out");
int N,cnt;
bool vx[14];
bool vy[14];
bool vs1[28];
bool vs2[28];
int ans[14];

void dfs(int x){
    if(x == N+1){
        if(cnt < 3){
            out << ans[1];;
            for(int i = 2; i <= N; i++){
                out << ' ' << ans[i];
            }
            out << endl;
        }
        cnt++;
        return;
    }

    for(int y = 1; y <= N; y++){ 
        if(!vx[x] && !vy[y] && !vs1[y+x] && !vs2[x-y+N] ){
            vx[x] = true;
            vy[y] = true;
            vs1[y+x] = true;
            vs2[x-y+N] = true;
            if(cnt < 3) ans[x] = y;
            dfs(x+1);
            vx[x] = false;
            vy[y] = false;
            vs1[y+x] = false;
            vs2[x-y+N] = false;
        }
    }
}

int main(){
    in >> N;
    dfs(1);
    out << cnt << endl;
}
