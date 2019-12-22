/*
ID: billyz43
PROG: elevator
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
std::ifstream in("elevator.in");
std::ofstream out("elevator.out");
using namespace std;
int K,mx;
struct node{
    int h,a,c;
    
    bool operator < (const node& o) const{
        return a < o.a;
    }
};
node e[401];
//int dp[401][40002];
int dp[2][40002];

int dfs(){
    int a = 0,b = 1;
    for(int i = 1; i <= K; i++){
        //dp[i][0] = 0;
        for(int j = 1; j <= mx; j++){
            if(j > e[i].a){
                dp[b][j] = max(dp[a][j],dp[b][e[i].a]);
            } else{
                dp[b][j] = 0;
                for(int k = 0; k <= e[i].c; k++){
                    if(j-k*e[i].h < 0) break;
                    int tmp = dp[a][j-k*e[i].h]+k*e[i].h;
                    dp[b][j] = max(dp[b][j],tmp);
                } 
            }
        }
        swap(a,b);
    }
    return dp[a][mx];    
}

int main(){
    in >> K;
    for(int i = 1; i <= K; i++){
        in >> e[i].h >> e[i].a >> e[i].c;
        mx = max(mx,e[i].a);
    }
    sort(e+1,e+K+1);
    int res = dfs();
    out << res << endl;
}
