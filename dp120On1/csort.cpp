/*
ID: billyz43
PROG: cfair
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
std::ifstream in("cfair.in");
std::ofstream out("cfair.out");
using namespace std;
int ans = 0;
int N;
int P[402];
int o[402];
int d[401][401];

bool cmp(int a, int b){
    return P[a] < P[b];
}

void print(){
    for(int i = 0; i < N; i++){
        cout  << o[i] << ' ';
    }
    cout << endl;
}

int dfs(){
    int dp[N+1];
    dp[1] = 1;
    
    for(int i = 2; i <= N; i++){
        if(d[1][i] <= P[i]){
            dp[i] = 1;
        } else{
            dp[i] = 0;
        }        
    }
    for(int i = 0; i < N; i++){
        o[i] = i+1;
    }
    sort(o,o+N,cmp);
//    print();
    

    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            int i = o[a], j= o[b];
            if(i == j) continue;
            if(P[i] + d[i][j] <= P[j]){
                if(dp[j] < dp[i]+1){
                    dp[j] = dp[i]+1;
                }
            }      
        }   
    }   

    int mv = 0;
    for(int i = 1; i <= N; i++){
        if(dp[i] > mv) mv = dp[i];
    }
    return mv;
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        in >> P[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            in >> d[i][j];
        }
    }
    int ans = dfs();   
    out << ans << endl;
}
