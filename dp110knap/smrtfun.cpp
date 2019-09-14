/*
ID: billyz43
PROG: smrtfun
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
std::ifstream in("smrtfun.in");
std::ofstream out("smrtfun.out");
using namespace std;
int N;
int s[101],f[101];
int res;

int dfs(int ts,int tf, int i){
    if(i == N){
        if(ts >= 0 && tf >= 0){
            return ts+tf;
        }
        return 0;
    }

    return max(dfs(ts+s[i],tf+f[i],i+1), dfs(ts,tf,i+1));
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> s[i] >> f[i];
    }
    res = dfs(0,0,0);
    cout << res << endl;
}
