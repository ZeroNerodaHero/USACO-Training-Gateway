/*
ID: billyz43
PROG: treasures
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
std::ifstream in("treasures.in");
std::ofstream out("treasures.out");
using namespace std;
struct node{
    int x,y,p,c,sx,ex;;
    bool operator < (node const& o) const{
        if(sx == o.sx) return ex < o.ex;
        return sx < o.sx;
    }
};

int N;
node ar[1000];
int dp[1005];
int ans;

void print(){
    for(int i = 0; i < N; i++){
        cout << i << " " << dp[i] << endl;
    }
}

int over(int i, int j){
    int b = (ar[i].ex - ar[j].sx);
    if(b < 0) b = -b;
    if(b&1){
        b /= 2;
        return b*b+b;
    } else{
        b /= 2;
        return b*b;
    }
}

void dfs(){
    for(int i = 0; i < N; i++){
        dp[i] = ar[i].p - ar[i].c; 
    }
    ans = max(ans,dp[0]);

//cout << "dp " <<0 << ' '<<  dp[0] << endl;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(ar[i].ex <= ar[j].ex){
                dp[j] += ar[i].p;
//                ans = max(ans,dp[j]);
//cout << "\tdp j " <<j << ' '<<  dp[j] << endl;
            } else{
                int a = dp[j] + ar[i].p - ar[i].c;;
                if((ar[j].ex - ar[i].sx) > 1){
                    a+=over(j,i);
//cout << "over " << over(j,i) << endl;
                }
                dp[i] = max(dp[i],a);
//cout << "\tdp i " <<i << ' '<<  dp[i] << endl;
            }
        }
//cout << "dp i " <<i << ' '<<  dp[i] << endl;
    }

    for(int i = 0; i < N; i++){
        if(dp[i] > ans) ans = dp[i];
    }
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> ar[i].x >> ar[i].y >> ar[i].p;
        ar[i].sx = ar[i].x+ar[i].y;
        ar[i].ex = ar[i].x-ar[i].y;
        ar[i].c = (ar[i].y* ar[i].y);
    }
    sort(ar,ar+N);
    dfs();
//    print();
    out << ans << endl;
}

