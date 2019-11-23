/*
ID: billyz43
PROG: weight
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
std::ifstream in("weight.in");
std::ofstream out("weight.out");
using namespace std;
int N,K;
int ans[1005];
int pos[1005];
int cal[2005];

bool isW(int a){
    for(int i = 0; i < K; i++){
        if(pos[i] == a) return true;
    }
    return false;
}

bool dfs(int i,int j,int p, int ls, int rs){
    if(p == 2*N) return true;   
    
    int l = cal[p] - ls;
    if(i < N && isW(l)){
        if(i < j){
            ans[i] = l;
            if(dfs(i+1,j,p+1,cal[p],rs)){
                return true;
            }
        } else{
            if(l == ans[i]){
                if(dfs(i+1,j,p+1,cal[p],rs)){
                    return true;
                }
            }
        }
    }
    int r = cal[p] - rs;
    if(j > 0 && isW(r)){
        if(i < j){
            ans[j-1] = r;
            if(dfs(i,j-1,p+1,ls,cal[p])){
                return true;
            }
        } else{
            if(r == ans[j-1]){
                if(dfs(i,j-1,p+1,ls,cal[p])) return true;
            }
        }
    }
    return false;
}

int main(){
    in >> N >> K;
    for(int i = 0; i < K; i++){
        in >> pos[i];       
    }   

    for(int i = 0; i < 2*N; i++){
        in >> cal[i];
    }
    sort(cal,cal+2*N);
    if(dfs(0,N,0,0,0)){
        for(int i = 0; i < N; i++){
            out << ans[i] << endl;
        }
    } else{
        out << "0" << endl;
    }
}
