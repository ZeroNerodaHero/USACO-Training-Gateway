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
    int c,r,l;
    bool operator< (const node& o) const{
        if(c == o.c) return r < o.r;
        return c < o.c;
    }
};
node b[1000];
int N,K,B;

int area(int i, int j){
    int r = b[i].r;
    bool r2 = false;
    int c1 = b[i].c;
    int c2 = 0;
    for(int s = i; s <= j; s++){
        if(b[s].r != r){
            r2= true;
        }
        c2 = max(c2,b[s].c+b[s].l-1);
    }

    int x = c2-c1+1;;
    if(r2) x<<=1;
    return x;
}

bool cmp(node& a, node& b){
    if(a.r == b.c) return a.c < b.c;
    return a.r < b.r;
    
}
int dfs(int n, int k){
    if(k == 1){
        return area(n,N-1);
    }
    int res = INF;
    for(int i = n; i < N-k+1; i++){
        int ar = area(n,i) + dfs(i+1,k-1);
        res = min(res,ar);
    }
    return res;
}

int main(){
    in >> N >> K >> B;

    for(int i = 0; i < N; i++){
        in >> b[i].r >> b[i].c;
    }      
    sort(b,b+N,cmp);
    int j = 0; 
    b[j].l = 1;
    for(int i = 1; i < N; i++){
        if(b[i].r == b[j].r && b[i].c == b[j].c + b[j].l){
            b[j].l++;
        } else{
            j++;
            b[j].r = b[i].r;
            b[j].c = b[i].c;
            b[j].l = 1;
        }           
    }
    N = j+1;
    sort(b,b+N);
    int ans = dfs(0,K);   
    out << ans << endl;
}
