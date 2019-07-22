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
#define SIZE 50
#define BASE 1000000000
using namespace std;
std::ifstream in("vans.in");
std::ofstream out("vans.out");
int N;
int row;
int a = 0, b = 1;

struct big{
    big() {
        memset(d,0,sizeof(d));
        d[0] = 0;
        w = 0;
    }
    big(int a){
        memset(d,0,sizeof(d));
        d[0] = a;
        w = 0;
    }
    big& operator += (const big& o){
        w = max(w,o.w);
        int carry = 0;
        for (int i = 0; i <= w; i++){
            d[i] += o.d[i]+carry;
            if(d[i] >= BASE){
                carry = 1;
                d[i] -= BASE;
            } else{
                carry = 0;
            }
        }
        if(carry == 1){
            w++;
            d[w] = 1;
        }
//        cout << *this << endl;
        return *this;  
    }

    int d[SIZE], w;
};
big ans;
unordered_map<int,big> m[2];
ostream& operator<< (ostream &os, big& a){
        os << a.d[a.w];
        for(int i = a.w-1; i >= 0; i--){
            os.fill('0');
            os.width(8);
            os << a.d[i];
        }
        return os;
    }
    
void prints(int cur, char ch){
    cout << ' ' << ch << ' ';
    for(int i = 0; i < 4; i++){
        cout << ((cur>>(i*2))&3) << ":";
    }
}

void printa(big a){
    cout << a.d[a.w];
    for(int i = a.w-1; i >= 0; i--){
        cout.fill('0');
        cout.width(8);
        cout << a.d[i];
    }
    cout << endl;
}

void dfs(int c, int l, int s, int cur, bool mod){
//    cout << "\tc " << c << "\tL " << l; prints(cur,'C'); cout << "\tmod " << mod << endl;
    if(c == 4){
        if(l == 0){
            m[b][cur] += m[a][s];
//            cout << "\tcur" << cur << " m[b][cur] " << m[b][cur] << endl;
        } else{
//            cout << "\tinvalid" << endl;
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
//                cout << "j " << j << endl;
                dfs(c+1,0,s,cur,0);
            }
        } else if(u == 2 && l == 1){
            if(c == 3 && row == N && cur == 0){
                ans += m[a][s];
 //               cout << "add " << m[a][s] << endl; 
 //               cout << "**ans " << ans << endl; 
            } else{
//                cout << "\tcycle" << endl;
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
    big tmp(1);
    m[a][0x99] = tmp;
    m[a][0x81] = tmp;
    for(row = 2; row <= N; row++){
        m[b].clear();
        for(auto& i: m[a]){
//            cout << row << " state " << i.first; prints(i.first,'S'); cout << endl;
            dfs(0,0,i.first,0,false);           
 //           cout << "ans " << ans << endl;
        }
        a ^= 1;
        b ^= 1;
    } 
    ans += ans;
//    cout << ans << endl;
    out << ans << endl;
}
