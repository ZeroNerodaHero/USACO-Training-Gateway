/*
ID: billy
PROG: vans
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("vans.in");
std::ofstream out("vans.out");
int N,ans = 0;
int row;
unordered_map<int,int> m[2];
int a = 0, b = 1;

void prints(int cur, char ch){
    cout << ' ' << ch << ' ';
    for(int i = 0; i < 4; i++){
        cout << ((cur>>(i*2))&3) << ":";
    }
}

void dfs(int c, int l, int s, int cur, bool mod){
    cout << "\tc " << c << "\tL " << l; prints(cur,'C'); cout << "\tmod " << mod << endl;
    if(c == 4){
        if(l == 0){
            m[b][cur] += m[a][s];
            cout << "\tcur" << cur << " m[b][cur] " << m[b][cur] << endl;
        } else{
            cout << "\tinvalid" << endl;
        }
        return;
    }

    int u = (s>>(c*2))&3;
            if(mod &&u ){
                u = 1;
                mod = false;
            }
    if(u == 0 && l == 0){
        dfs(c+1,2,s,(cur|(1<<(c*2))), mod);
    } else if(u && l){
        if(u == l) {
            if(u == 1){
                dfs(c+1,0,s,cur,1);
            } else{
                int j;
                for(j = c-1; j >= 0; j--){
                    if(cur&(3<<(j*2))) break;
                }
                cur ^= 3<<(2*j);
                cout << "j " << j << endl;
                dfs(c+1,0,s,cur,0);
            }
        } else if(u == 2 && l == 1){
            if(c == 3 && row == N && cur == 0){
                ans += m[a][s];
                cout << "\tans " <<  m[a][s]<< endl;
            } else{
                cout << "\tcycle" << endl;
            }
        } else{
            dfs(c+1,0,s,cur,mod);
        } 
    } else{
        if(u){
            dfs(c+1,u,s,cur,mod);
            dfs(c+1,0,s,cur|(u<<(c*2)),mod);
        } else{
            dfs(c+1,l,s,cur,mod);
            dfs(c+1,0,s,cur|(l<<(c*2)),mod);
        }
    }
}

int main(){
    in >> N;
    m[a][0x0] = 1;
    //m[a][0x99] = 1;
    //m[a][0x81] = 1;
    for(row = 1; row <= N; row++){
        m[b].clear();
        for(auto& i: m[a]){
            cout << row << " state " << i.first; prints(i.first,'S'); cout << endl;
            dfs(0,0,i.first,0,false);           
        }
        a ^= 1;
        b ^= 1;
    } 
    ans += ans;
    cout << ans<< endl;
}
