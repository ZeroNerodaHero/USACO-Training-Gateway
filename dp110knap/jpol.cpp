/*
ID: billyz43
PROG: jpol
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
std::ifstream in("jpol.in");
std::ofstream out("jpol.out");
using namespace std;
int K, N,s;
int c[182];
int ind[182];
bool se[121];
char dp[121][60*1000];

bool cmp(int a, int b){
    return c[a] > c[b];
}

void sol(){
    for(int i = 0; i < 2 * K; i++){
        s += c[ind[i]];
    }
    s /= 2;
//    cout << "s\t" <<s << endl;

    dp[0][0] = 1;
    for(int i = 1; i <= s; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= 2*K; i++){
        dp[i][0] = 1;
//        cout << i << endl;
        for(int j = 1; j <= s; j++){
            if(dp[i-1][j] > 0){
                dp[i][j] = dp[i-1][j];
            } else{
                dp[i][j] = 0;
            }       
            if(j >= c[ind[i-1]] && dp[i-1][j-c[ind[i-1]]]){
                if(dp[i][j] < dp[i-1][j-c[ind[i-1]]]+1){
                    dp[i][j] = dp[i-1][j-c[ind[i-1]]]+1;
                }   
            }
            if(j > N && dp[i][j] == K+1){
//                cout << j << " - dp: " << dp[i][j] << endl;
                for(int k = i; k > 0; k--){
                    if(dp[k-1][j] == dp[k][j]){
                    } else{
                        se[k-1] = true;
                        j -= c[ind[k-1]];        
                    }
                }
                break;
            }
        }
    }  
}

int main(){
    in >> K;
    N = 500 * K;
    for(int i = 0; i < 3*K; i++){
        in >> c[i];
        ind[i] = i;
    }   
    sort(ind,ind+3*K,cmp);
#if 0
    for(int i = 0; i < 3*K; i++){
        cout << ind[i] << ' ';
    }
    cout << endl;
#endif
    sol();
    for(int i = 0; i < 2* K; i++){
        if(se[i]) out << ind[i]+1 << endl;
    }       
    for(int i = 0; i < 2* K; i++){
        if(!se[i]) out << ind[i]+1 << endl;
    }       
    for(int i = 2*K; i < 3*K; i++){
        out << ind[i]+1 << endl;
    }
}
