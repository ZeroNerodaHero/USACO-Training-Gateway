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
int dp[2][401][1001];
int sum[2][402][1002];

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
        dp[0][i][i] = dp[1][i][i] = abs(L-ar[i]);
        sum[0][i][i] = sum[1][i][i] = abs(L-ar[i]);
    } 
//    dp[0][0][0] = dp[0][3][3] = INF;
//    dp[1][0][0] = dp[1][3][3] = INF;

    for(int l = 1; l < N; l++){
        for(int i = 0; i + l <  N; i++){
            int j = i+l;
            int t0, t1;
            int d0, d1;
            
            d0 =dp[0][i+1][j] + ar[i+1]-ar[i];
            d1 = dp[1][i+1][j] + ar[j] - ar[i];
            t0 = sum[0][i+1][j] + d0 * (N-l);
            t1 = sum[1][i+1][j] + d1 * (N-l);
            
            if (t0 < t1) {
                dp[0][i][j] = d0;
                sum[0][i][j] = sum[0][i+1][j] + dp[0][i][j];
            } else {
                dp[0][i][j] = d1;
                sum[0][i][j] = sum[1][i+1][j] + dp[0][i][j];
            }

            d0 = dp[0][i][j-1] + ar[j]-ar[i];
            d1 = dp[1][i][j-1] + ar[j]-ar[j-1];
            t0 = sum[0][i][j-1] + d0 * (N-l);
            t1 = sum[1][i][j-1] + d1 * (N-l);

            if (t0 < t1) {
                dp[1][i][j] = d0;
                sum[1][i][j] = sum[0][i][j-1] + d0;;
            } else {
                dp[1][i][j] = d1; 
                sum[1][i][j] = sum[1][i][j-1] + d1;
            }
        }   
    }
    //print();
    return min(sum[0][0][N-1],sum[1][0][N-1]);
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
