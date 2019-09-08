/*
ID: billy
PROG: dice
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
#define MAXN 1030
std::ifstream in("dice.in");
std::ofstream out("dice.out");
using namespace std;
double dp[2][33][MAXN];
int ar[2][32][16];
int d[2],s[2];

void sol(int k){
    for(int i = 0; i < s[k]; i++){
        dp[k][1][ar[k][0][i]] += 1;
    }

    for(int i = 2; i <= d[k]; i++){
        for(int j = 0; j < s[k]; j++){
            for(int t = 0; t < MAXN; t++){
                if(t >= ar[k][i-1][j]){
                    dp[k][i][t] += dp[k][i-1][t-ar[k][i-1][j]];
                }
            }
        }    
    }
}

int main(){
    int t[2] = {1,1};
    for(int k = 0; k < 2; k++){
        in >> d[k] >> s[k];
        for(int i  = 0; i < d[k]; i++){
            t[k] *= s[k];
            for(int j = 0; j < s[k]; j++){
                in >> ar[k][i][j];                    
            }
        }
        sol(k);
#if 0 
        cout << d[k] << ' ' << s[k] << ' ' << t[k]<< endl;
        for(int i = 0; i < 30; i++){
            if(dp[k][d[k]][i] > 0)
                cout << dp[k][d[k]][i] << " (" << i << ") ";
        }
        cout << endl;
#endif
    }
    
    int s1=0,s2=0;
    bool issam = true,isprob = true;
    for(int i = 0; i < MAXN; i++){
        if(dp[0][d[0]][i] != 0) s1++; 
        if(dp[1][d[1]][i] != 0) s2++;

        if(issam){
            if((dp[0][d[0]][i] == 0 &&  dp[1][d[1]][i] > 0) ||
               (dp[0][d[0]][i] > 0 &&  dp[1][d[1]][i] == 0 )){
                issam = isprob = false;
            }
            if(isprob){
                if((dp[0][d[0]][i] * t[1]) != (dp[1][d[1]][i] * t[0])){
                    isprob = false;
                }
            }
        }
    }
    if(!issam){
        out << "N N\n";
    } else{
        out << "Y ";
        if(isprob) out <<"Y\n";
        else out << "N\n";
    }
    out << s1 << ' ' << s2 << endl;
}
