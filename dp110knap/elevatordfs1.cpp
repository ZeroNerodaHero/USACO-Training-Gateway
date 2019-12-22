/*
ID: billyz43
PROG: elevator
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
std::ifstream in("elevator.in");
std::ofstream out("elevator.out");
using namespace std;
int K;
struct node{
    int h,a,c;
    
    bool operator < (const node& o) const{
        return a < o.a;
    }
};
node e[401];

int dfs(int y, int h){
    if(y > K) return h;

    int mx = 0;
    for(int i = 0; i <= e[y].c; i++){
        int ch = h+e[y].h * i;
        if(ch > e[y].a) break;
        mx = max(mx,dfs(y+1,ch));
    }
    return mx;
}

int main(){
    in >> K;
    for(int i = 1; i <= K; i++){
        in >> e[i].h >> e[i].a >> e[i].c;
    }
    sort(e+1,e+K+1);
    int res = dfs(1,0);
    cout << res << endl;
}
