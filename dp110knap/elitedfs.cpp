/*
ID: billyz43
PROG: elite
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
#define INF 9999
std::ifstream in("elite.in");
std::ofstream out("elite.out");
using namespace std;
int ar[101];
int N, S;

int dfs(int p,int sum, int cnt){
    if(sum >= S) return 0;
    if(cnt == N){
        if(sum < S) return 1;
        return 0;
    }
    if(p == 100){
        return 0;
    }
    
    int ans = dfs(p+1,sum,cnt);
    ans += dfs(p+1,sum+ar[p],cnt+1);
    return ans;
}

int main(){
    in >> N >> S;
    for(int i = 1; i <= 100; i++){
        ar[i] = i * i;
    }

    int ans = dfs(1,0,0);
    out << ans << endl;
}
