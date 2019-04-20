/*
ID: billy
PROG: rockers
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
std::ifstream in("rockers.in");
std::ofstream out("rockers.out");

int N,T,M;
int l[20];
int dp[21][21];

void print(){
    for(int i = 1; i <= M; i++){
        for(int j = 0; j <= T; j++){
            cout << dp[i][j] << ' ';
        } cout << endl;
    }
}

int main(){
    in >> N >> T >> M;
    for(int i = 0; i < N; i++){
        in >> l[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = M; j > 0; j--){
            for(int k = 0; k <= T; k++){
                if(k >= l[i]){
                    dp[j][k-l[i]] = max(dp[j][k-l[i]],dp[j][k]+1);
                } else{
                    if(j < M){
                        dp[j+1][T-l[i]] = max(dp[j+1][T-l[i]],dp[j][k]+1);
                        //for (int o=l[i];o<=T; ++o) dp[j+1][o-l[i]] = max(dp[j+1][o-l[i]],dp[j][o]+1);
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= T; i++){
        ans = max(ans,dp[M][i]);
    }
//    print();
    out << ans << endl;
}
