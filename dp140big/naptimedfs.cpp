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

int dfs(int s,int c, int b, bool isS){
    //cout << c << endl;
    if(b == B) return 0;
    if(c == s+N) return 0;

    int ans = 0;
    if(isS){
        ans = max(ans,U[c]+dfs(s,c+1,b+1,isS));
    } else{
        ans = max(ans,dfs(s,c+1,b+1,true));
    }
    ans = max(ans,dfs(s,c+1,b,false));
    return ans;
}

int main(){
    in >> N >> B;
    for(int i = 0; i < N; i++){
        in >> U[i];
        U[i+N] = U[i]; 
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans,dfs(i,i+1,1,true));
    }
    out << ans << endl;
}
