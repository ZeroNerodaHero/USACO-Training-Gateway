/*
ID: billyz43
PROG: cowq
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <iomanip>
#define INF 9999
std::ifstream in("cowq.in");
std::ofstream out("cowq.out");
using namespace std;
int N, B, J, L;
double dp[101];
double dc[101][101];
int ans;

void print(){
    for(int i = 0; i < N; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
}

double dfs(){
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= N; i++){
        for(int k = 1; k <= i; k++){
            int l = i-k;
            double cnt = dp[k-1] * dp[l];
            dp[i] += cnt;
        }
        if(i <= L) continue;
        for(int k = 1; k  <= N; k++){  
            int j = k+i-1;
            if(k > B) break;
            if(j < J) continue;

            for(int m = k; m <= j; m++){
                if(m < B){
                    dc[k][j] += dp[m-k] * dc[m+1][j]; 
                }
                else if(m > B && m <= J){
                    dc[k][j] += dp[m-k] * dp[j-m];
                } 
                else if(m > J){
                    dc[k][j] +=  dc[k][m-1] * dp[j-m];
                } 
            }
     //       cout << "\t" << k << ' ' << j << ' ' << dc[k][j] << endl;;
        }
    } 

    double ans = 0;
    for(int k = 1; k <= N; k++){  
        int l = N-k;
        if(k < B){
            ans += dp[k-1] * dc[k+1][N]; 
        }
        else if(k > B && k <= J){
            ans += dp[k-1] * dp[l];
        } 
        else if(k > J){
            ans += dc[1][k-1] * dp[N-k];
        } 
   //     cout << k << "\t" <<  dc[k][N] << ' ' << dp[N] << endl;;
    }
 //   cout << ans << endl;
    ans /= dp[N];
    return ans;
}

int main(){
    bool cha = false;
    in >> N >> B >> J;
//    cout << "N " << N << endl;
    if(B > J){
        swap(B,J);
        cha = true;
    }
    L = J-B;
    double ans = dfs();
    //print();
    if(cha) ans = 1-ans;
    out << fixed << setprecision(6);
    out << ans << endl;
}
