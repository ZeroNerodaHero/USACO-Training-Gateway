/*
ID: billy
PROG: lazy
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
#define INF (1<<28)
std::ifstream in("lazy.in");
std::ofstream out("lazy.out");
using namespace std;
struct node{
    int c,r;
    bool operator< (const node& o) const{
        if(c == o.c) return r < o.r;
        return c < o.c;
    }
};
node b[1000];
int N,K,B;

int area1(int i, int j){
    if(b[i].r == b[j].r){
        return (b[j].c-b[i].c+1);
    }
    int r = b[i].r;
    bool r2 = false;
    int c1 = INF, c2 = 0;
    for(int s = i; s <= j; s++){
        c1 = min(c1,b[s].c);
        c2 = max(c2,b[s].c);
    }
    return (c2-c1+1)*2;
}
int area2(int i, int j){
    int r = b[i].r;
    bool r2 = false;
    for(int s = i+1; s <= j; s++){
        if(b[s].r != r){
            r2= true;
            break;
        }
    }

    int x = b[j].c-b[i].c+1;
    if(r2) x<<=1;
    return x;
}

int area(int i, int j,bool t){
    return (t)? area1(i,j) : area2(i,j);
}

bool cmp(node& a, node& b){
    if(a.r == b.c) return a.c < b.c;
    return a.r < b.r;
    
}
int dfs(int n, int k, bool t){
    if(k == 1){
        return area(n,N-1,t);
    }
    int res = INF;
    for(int i = n; i < N-k+1; i++){
        int ar = area(n,i,t) + dfs(i+1,k-1,t);
        res = min(res,ar);
    }
    return res;
}

int main(){
    in >> N >> K >> B;

    for(int i = 0; i < N; i++){
        in >> b[i].r >> b[i].c;
    }      
    sort(b,b+N);
    int ans = dfs(0,K,false);   
    sort(b,b+N,cmp);
    ans = min(ans,dfs(0,K,true));   
    out << ans << endl;
}
