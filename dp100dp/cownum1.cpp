/*
ID: billy
PROG: cownum
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>
#include <cmath>
std::ifstream in("cownum.in");
std::ofstream out("cownum.out");
using namespace std;
int N,mod;
int num[1001];
int dp[1001][1001];

void print(){
    for(int i = 0; i < N; i++){
        cout << num[i];
    } 
    cout << endl;
}

int dfs(int d){
    if(d == -1){
        print();
        return 1;
    }
    int ans = 0;
    int mx = N;
    if(d+2 < N){
        mx = min(mx,num[d+2]-1);   
    }
    if(d+3 < N){
        mx = min(mx,num[d+3]-1);   
    }
    for(int i = 1; i <= mx; i++){
        num[d] = i;
        ans += dfs(d-1);
    }
    return ans;
}

int main(){
    in >> N >> mod;
    int ans = dfs(N-1);

    out << ans << endl;
}
