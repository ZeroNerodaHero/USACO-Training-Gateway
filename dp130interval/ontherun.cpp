/*
ID: billyz43
PROG: ontherun
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 0x1f1f1f
std::ifstream in("ontherun.in");
std::ofstream out("ontherun.out");
using namespace std;
int N, L;
vector<int> ar;
int dp[2][1001][2];
int sum[2][1002][2];

void printa()
{
    cout << "L: " << L << endl;
    for(int i = 0;i < N; i++) cout << ar[i] <<' ';cout << endl;
}


void print(){
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[0][i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[1][i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            cout << sum[0][i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            cout << sum[1][i][j] << ' ';
        }
        cout << endl;
    }
}

int dfs(){
    for(int i = 0; i < N; i++){
        dp[0][i][0] = dp[1][i][0] = abs(L-ar[i]);
        sum[0][i][0] = sum[1][i][0] = abs(L-ar[i]);
    } 
//    dp[0][0][0] = dp[0][3][3] = INF;
//    dp[1][0][0] = dp[1][3][3] = INF;

    int a = 0, b = 1;
    for(int l = 1; l < N; l++){
        for(int i = 0; i + l <  N; i++){
            int j = i+l;
            int t0, t1;
            int d0, d1;
            
            d0 =dp[0][i+1][a] + ar[i+1]-ar[i];
            d1 = dp[1][i+1][a] + ar[j] - ar[i];
            t0 = sum[0][i+1][a] + (d0-d1) * (N-l);
            t1 = sum[1][i+1][a];
            
            if (t0 < t1) {
                dp[0][i][b] = d0;
                sum[0][i][b] = sum[0][i+1][a] + dp[0][i][b];
            } else {
                dp[0][i][b] = d1;
                sum[0][i][b] = sum[1][i+1][a] + dp[0][i][b];
            }

            d0 = dp[0][i][a] + ar[j]-ar[i];
            d1 = dp[1][i][a] + ar[j]-ar[j-1];
            t0 = sum[0][i][a] + (d0-d1) * (N-l);
            t1 = sum[1][i][a];

            if (t0 < t1) {
                dp[1][i][b] = d0;
                sum[1][i][b] = sum[0][i][a] + d0;;
            } else {
                dp[1][i][b] = d1; 
                sum[1][i][b] = sum[1][i][a] + d1;
            }
        }   
        a ^= 1;
        b ^= 1;
    }
    //print();
    return min(sum[0][0][a],sum[1][0][a]);
}

int main(){
    in >> N >> L;
    ar.resize(N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        in >> ar[i];
        sum += ar[i];
    }   
    sort(ar.begin(),ar.end());
//    printa();

    auto st = lower_bound(ar.begin(),ar.end(),L);
    if(st == ar.end()){
        out << sum << endl;
        return 0;
    }
    st--;
    int ans = dfs();
    out << ans << endl;
}
