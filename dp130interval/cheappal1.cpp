/*
ID: billy
PROG: cheappal
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
#define INF 9999
std::ifstream in("cheappal.in");
std::ofstream out("cheappal.out");
using namespace std;

struct cost{
    int a, d;
};
int N, M;
string s;
cost cha[128];

int dfs(int i, int j){
    if(i >= j) return 0;
    int ans = dfs(i+1,j)+min(cha[s[i]].a,cha[s[i]].d);
    ans = min(ans,dfs(i,j-1)+min(cha[s[j]].a,cha[s[j]].d));
    if(s[i] == s[j]){
        ans = min(ans,dfs(i+1,j-1));
    }
    cout << i << ' ' << j << ' ' << ans << endl;
    return ans; 
}

int main(){
    in >> N >> M >>s;
    for(int i = 0; i < N; i++){
        char ccha;
        int ca,cd;
        in >> ccha >> ca >> cd;
        cha[ccha].a = ca;
        cha[ccha].d = cd;
    }
    int ans = dfs(0,M-1);
    out << ans << endl;
}
