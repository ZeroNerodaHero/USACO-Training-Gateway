/*
ID: billyz43
PROG: treasures
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
std::ifstream in("treasures.in");
std::ofstream out("treasures.out");
using namespace std;
struct node{
    int x,y,p,c,sx,ex;;
    bool operator < (node const& o) const{
        if(sx == o.sx) return ex < o.ex;
        return sx < o.sx;
    }
};

int N;
node ar[1000];

int over(int i, int j){
    int b = (ar[j].sx - ar[i].ex)/2;
    return b*b;
}

bool v[1000];
int dfs(int c){
    if(c == N){
        return 0;
    }
    int ans = dfs(c+1);
    int sum = 0;
    for(int i = 0; i < c; i++){
        if(v[i] && ar[c].sx < ar[i].ex){
            sum = max(sum,over(i,c));
        }
    }
    v[c] = true;
    int tmp = ar[c].p-ar[c].c+sum+dfs(c+1);
    ans = max(ans,tmp);
    v[c] = false; 
    return ans;
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> ar[i].x >> ar[i].y >> ar[i].p;
        ar[i].sx = ar[i].x+ar[i].y;
        ar[i].ex = ar[i].x-ar[i].y;
        ar[i].c = (ar[i].y* ar[i].y);
    }
    sort(ar,ar+N);
    int ans = dfs(0);
    out << ans << endl;
}
