/*
ID: billyz43
PROG: cowrun
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
#include <climits>
#define INF 0x4f4f
std::ifstream in("cowrun.in");
std::ofstream out("cowrun.out");
using namespace std;
int N;
int ar[1001];
struct node{
    int t, d;
};
node dp[2][1000][1000];

int dfs(int st){
    for(int i = 0; i < N; i++){
        dp[0][i][i].t = dp[0][i][i].d = INF+abs(ar[i]);
        dp[1][i][i].t = dp[1][i][i].d = INF+abs(ar[i]);
    }    

    dp[0][st][st].t = dp[0][st][st].d = 0;
    dp[1][st][st].t = dp[1][st][st].d = 0;

    for(int l = 1; l < N; l++){
        for(int s = 0, e = l; e < N; e++,s++){
            int t1 = dp[0][s+1][e].t + abs(ar[s]-ar[s+1]);
            int t2 = dp[1][s+1][e].t + abs(ar[s]-ar[e]);
            int d1 = dp[0][s+1][e].d + t1;
            int d2 = dp[1][s+1][e].d + t2;

//            cout << s << " " << e << " 0 t\t" << t1 << " d\t" << d1 << endl;;
//            cout << s << " " << e << " 0 t\t" << t2 << " d\t" << d2 << endl;;

            if(t1 < t2){
                dp[0][s][e].t = t1;
                dp[0][s][e].d = d1;
            } else{
                dp[0][s][e].t = t2;
                dp[0][s][e].d = d2;
            }

            t1 = dp[0][s][e-1].t + abs(ar[e]-ar[s]);
            t2 = dp[1][s][e-1].t + abs(ar[e]-ar[e-1]);
            d1 = dp[0][s][e-1].d + t1;
            d2 = dp[1][s][e-1].d + t2;

//            cout << s << " " << e << " 0 t\t" << t1 << " d\t" << d1 << endl;;
//            cout << s << " " << e << " 0 t\t" << t2 << " d\t" << d2 << endl;;

            if(t1 < t2){
                dp[1][s][e].t = t1;
                dp[1][s][e].d = d1;
            } else{
                dp[1][s][e].t = t2;
                dp[1][s][e].d = d2;
            }

            
        }
    }
    return min(dp[0][0][N-1].d,dp[1][0][N-1].d);   
}

int main(){
    in >> N;
    ar[0] = 0;
    for(int i = 1; i <= N; i++){
        in >> ar[i];
    }
    N++;
    sort(ar,ar+N);
    int s = 0;
    for(int i =0; i < N; i++){
        if(ar[i] == 0){
            s = i;
            break;
        }
    }
    int ans = dfs(0);
    out << ans << endl;
}
