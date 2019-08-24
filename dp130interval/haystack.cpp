/*
ID: billy
PROG: haystack
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
std::ifstream in("haystack.in");
std::ofstream out("haystack.out");
using namespace std;

struct pt{
    int x,y;
    bool operator< (const pt& o) const{
        return x < o.x;
    }
};
int N;
pt p[201];

int dist(int x, int y, int k){
    return abs(x-p[k].x)+abs(y)+abs(p[k].y);;
}

int dfs(int x,int y, int i, int j){
//    cout << i << ' ' << j << endl;
    if(i > j) return 0;
    int res = dist(x,y,j)+dfs(p[j].x,p[j].y,i,j-1);
    for(int k = i; k < j; k++){
        int r = dist(x,y,k)+max(dfs(p[k].x,p[k].y,i,k-1),dfs(p[k].x,p[k].y,k+1,j));
        res = min(res,r);
    }
    return res;
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> p[i].x >> p[i].y;
    }
    sort(p,p+N);

    int ans = dfs(0,0,0,N-1);
    out << ans << endl;
}
