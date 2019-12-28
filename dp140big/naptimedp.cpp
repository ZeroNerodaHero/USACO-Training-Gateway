/*
ID: billyz43
PROG: naptime
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
std::ifstream in("naptime.in");
std::ofstream out("naptime.out");
using namespace std;
int N,B;
int U[7680];
int dp[2][100][3835];
int dp1[2][8000];

void print(){
    cout << "c "  << endl;
    for(int a = 0; a < 2; a++){
        for(int i = 0; i < 2*N; i++){
            for(int j = 1; j <= 2*B; j++){
                cout.width(3);
                cout << dp[a][i][j];
            }
        cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    for(int a = 0; a < 2; a++){
        for(int i = 0; i < 2*N; i++){
            cout << dp1[a][i] << ' ' ;
        }
        cout << endl;
    }
        cout << endl;
}

int dfs(){
    int a = 0,b = 1;
    for(int i = 1; i < 2*N; i++){
        for(int j = 2; j <= 2*B; j++){
            dp[0][b][j] = max(dp[0][a][j],dp[1][a][j]);
            dp[1][b][j] = max(dp[0][a][j-1],dp[1][a][j-1] + U[i]); 
        }
//        swap(a,b);

        int c = i;
        if(i > B){
            c = B;
        }
        dp1[0][i] = dp[0][b][c];
        dp1[1][i] = dp[1][b][c];
        a++,b++;
    }
    int ans = max(dp1[0][N-1],dp1[1][N-1]);
    for(int i = 0; i <= N-1; i++){
        int c = max(dp1[0][i],dp1[1][i] +U[i]);
        int d = max(dp1[0][i+N],dp1[1][i+N]) - c;
cout << i << " c= " << c << " d = " << d << endl;
        ans = max(ans,d);
    }
    print();
    return ans;
}

int main(){
    in >> N >> B;
    for(int i = 0; i < N; i++){
        in >> U[i];
        U[i+N] = U[i]; 
    }
    int ans = 0;
        memset(dp,0,sizeof(dp));
        ans =dfs();
    out << ans << endl;
}
