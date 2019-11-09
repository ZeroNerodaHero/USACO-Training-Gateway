/*
ID: billyz43
PROG: essay
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <list>
#include <cmath>
#define INF 0x3F3F3F3F
std::ifstream in("essay.in");
std::ofstream out("essay.out");
using namespace std;
int S,Q;
int w[1000];
int q[1000];
short dp[1002][5002];
void print(){
    for(int i = 0; i <= S; i++){
        for(int j = 0; j <= Q; j++){
            if(dp[i][j] < 0){
                cout << "| ";
                //cout << dp[i][j] << ' ';
            } else{
                cout << dp[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

short dfs(){
    memset(dp,0x80,sizeof(dp));
    dp[0][0] = 0;
    short ans = 0;
    for(int i = 1; i <= S; i++){
        for(int j = 0; j <= Q; j++){

            int ww = j + q[i-1];
            if(ww > Q){
                ww = Q;
                dp[i][j] = max(dp[i][j],dp[i-1][Q]);
#if 0 
                for(int k =j; k <= Q; k++){
                    dp[i][j] = max(dp[i][j],dp[i-1][k]);
                }
#endif
            } else{      
                dp[i][j] = max(dp[i][j],dp[i-1][ww]);
            }
            int qq = j - w[i-1];
            if(qq >= 0){
                dp[i][j] = max(dp[i][j]+0,dp[i-1][qq]+1);
            }
        } 
    }
//print();
    for(int i = 0; i <= Q; i++){
        ans = max(ans,dp[S][i]);
    }
    return ans;
}

int main(){
    in >> S >> Q;
    for(int i = 0; i < S; i++){
        in >> w[i] >> q[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans = dfs();
    out << ans  << endl;
}
