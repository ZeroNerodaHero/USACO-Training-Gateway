/*
ID: billy
PROG: betsy
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
std::ifstream in("betsy.in");
std::ofstream out("betsy.out");
int N, r;
int a = 0, b = 1;
bool visited[7][7];
int ans = 0;
unordered_map<int,int> m[2];

void dfs(int c, int l, int s, int cur, bool mod, int cnt){
    if(c == N){
        if(l == 0) m[b][cur] += m[a][s];
        return;
    }
    int u = (s>>(2*c)) & 3;
    if(mod){
        if(u == 1) cnt++;
        if(u == 2){
            if(cnt > 0) cnt--;
            else{
                u = 1;
                mod = false;
            }    
        }
    }
    if(u == 0 && l == 0){
        cur |= (1<<(2*c));
        dfs(c+1,2,s,cur,mod,cnt);
    } else if(u > 0 &&  l > 0){
        if(u == 1 && l == 1){
            dfs(c+1,0,s,cur,1,0);
        } else if(u == 2 && l == 2){
            int j = c-1;
            int k = 0;
            for(;j >= 0; j--){
                int bit = ((cur >> (2*j))&3);
                if(bit == 2) k++;
                if(bit == 1){
                    if(k > 0) k--;
                    else{
                        cur ^= (3<<(2*j));
                        break;
                    }
                }
            }
            dfs(c+1,0,s,cur,mod,cnt);
        } else if(u == 1 && l == 2){
            dfs(c+1,0,s,cur,mod,cnt);
        } else{
            if(r == N && c == N-1 && cur == 0){
                ans += m[a][s];
            }           
        }
    } else{
        int w = u?u:l;
        dfs(c+1,w,s,cur,mod,cnt);
        cur |= w<<(c*2);
        dfs(c+1,0,s,cur,mod,cnt);
    }
}

int main(){
    in >> N;
    if(N == 1){
        out << 1 << endl;
        return 0;
    }
    m[a][2<<(2*(N-1))|1] = 1;    
    for(r = 1; r <= N; r++){
        m[b].clear();
        for(auto& j: m[a]){
            dfs(0,0,j.first,0,0,0);
        }
        a^= 1;
        b^= 1;
    }
    out << ans << endl;
}
