/*
ID: billyz43
PROG: apples
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
std::ifstream in("apples.in");
std::ofstream out("apples.out");
using namespace std;

struct pt{
    int x,y;
    double t;
    pt(){};
    pt(int x, int y, int t): x(x),y(y),t(t) {};
    bool operator <(const pt& o) const{
        return t < o.t;
    }
};

int N,S;
pt P[5001];

int dp[5002];

double dist(int s, int e){
    return sqrt((P[s].x-P[e].x) * (P[s].x-P[e].x) + (P[s].y-P[e].y) * (P[s].y-P[e].y));
}

int sl(){
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = i-1; j >= 0; j--){ 
//cout << i << "-" << j << " " << dist(j,i) << endl;
            if(dp[j] >= 0 && (P[j].t + (dist(j,i)/S)) <= P[i].t){
//cout << '\t' << i << ' ' << j << ' ' << (P[j].t + (dist(j,i)/S)) << ' ' << P[i].t << endl;
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans,dp[i]);
    }
    return ans;
}

void print(){
    for(int i = 0; i < N; i++){
        cout << P[i].x << P[i].y << P[i].t << endl;
    }

}

int main(){
    in >> N >> S;
    P[0] = pt(0,0,0);
    for(int i = 1; i <= N; i++){
        in >> P[i].x >> P[i].y >> P[i].t;
    }
    sort(P,P+N+1);
//print();
    int ans = sl();   
    out << ans << endl;
}
