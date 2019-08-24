/*
ID: billy
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
#define INF 9999
std::ifstream in("ontherun.in");
std::ofstream out("ontherun.out");
using namespace std;
int N, L;
vector<int> ar;
int ans = INT_MAX;

int dfs(int l, int t,int i, int j){
    cout << i << ' ' << j << ' ' << t << " " << l <<endl;
    if(i == -1 && j == N) return t;
    if(i == -1){
        return dfs(ar[j],t+ar[j]-l,i,j+1)+t;
    }
    if(j == N){
        return dfs(ar[i],t+l-ar[i],i-1,j)+t;
    }
    
    int ans = dfs(ar[i],l-ar[i]+t,i-1,j)+t;
    ans = min(ans,dfs(ar[j],ar[j]-l+t,i,j+1)+t);
    return ans;
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
    auto st = lower_bound(ar.begin(),ar.end(),L);
    if(st == ar.end()){
        cout << sum << endl;
        return 0;
    }
    st--;
    int ans = dfs(L,0,st-ar.begin(),st-ar.begin()+1);
    cout << ans << endl;
}
