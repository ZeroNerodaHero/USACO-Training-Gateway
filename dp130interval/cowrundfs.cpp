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
#define INF 0x4f4f4f4f
std::ifstream in("cowrun.in");
std::ofstream out("cowrun.out");
using namespace std;
int N;
int ar[1001];

int dfs(bool l,int i, int j,int c){
    if(i == 0 && j == N-1){
        return 0;
    }
    int ans = INF;
    int d = 0;
    if(l){
        if(i > 0){
            d =abs(ar[i-1]-ar[i])+c;
            ans = dfs(1,i-1,j,d) + d;
        }
        if(j-1 < N){
            d = abs(ar[j+1]-ar[i])+c;
            ans = min(ans,dfs(0,i,j+1,d) + d);
        }
        return ans; 
    }
    if(i > 0){
        d = abs(ar[i-1]-ar[j])+c;
        ans = min(ans,dfs(1,i-1,j,d)+d);
    }
    if(j-1 < N){
        d = abs(ar[j+1]-ar[j])+c;
        ans = min(ans,dfs(0,i,j+1,d)+d);
    }
    return ans;   
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
    for(int i = 0; i < N; i++){
        if(ar[i] == 0){
            s = i;
            break;
        }
    } 
    int ans = dfs(0,s,s,0);
    out << ans << endl;
}
