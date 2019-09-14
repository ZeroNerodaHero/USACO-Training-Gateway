/*
ID: billyz43
PROG: prime3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>
#include <math.h>
using namespace std;
std::ifstream in("prime3.in");
std::ofstream out("prime3.out");
int s;

struct mat{
    int a[5][5];

    bool operator< (const mat& o)const{
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(a[i][j] < o.a[i][j]) return true;
                if(a[i][j] > o.a[i][j]) return false;
            }
        }
        return false;
    }
};

bool nprime[100005];
int primen[10][200][5];
int primel[10][200][5];
int primef[10][200][5];
mat ans[101];
int cind[10];
int lind[10];
int linf[10];
int tab[5][5];
int has = 0;
bool st[0x99999];;

void print(){
    if(has) out << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            out << tab[i][j];
        }
        out << endl;
    }
}

void inline put(int a[]){
    int b = a[0] << 16 | a[1] << 12 | a[2] << 8 | a[3] << 4 | a[4];
//cout << "b :"<< hex << b << endl;
    st[b] = true;;
}


int tprime = 0;
void primes(){
    int N = sqrt(99999);
    for(int i = 2; i <= N; i++){
        if(nprime[i] == 0){
            for(int j = i+i; j < 99999; j+=i){
                nprime[j] = true;
            }
        }
    }
    for(int i = 2; i < 99999; i++){
        if(i < 10000){
            nprime[i] = true;
            continue;
        }
        if(nprime[i] == 0){
//            cout << i << endl;
            int x = i;
            int ind = i/10000;
            int &k = cind[ind];
            int cs = ind;
            bool last = true;
            bool first = true;
            primen[ind][k][0] = ind;
            primel[ind][lind[ind]][0] = ind;
            primef[ind][linf[ind]][0] = ind;
            for(int j = 4; j > 0; j--){
                int di = x%10;
                primen[ind][k][j] = di;
                primel[ind][lind[ind]][j] = di;
                primef[ind][linf[ind]][j] = di;
                x/=10;
                cs += primen[ind][k][j];
                if((di&1) == 0 || di == 5) last = false;
                if(di == 0) first= false;
            }
//if(cs == s)             cout <<i << ' ' <<  cs << endl;
            if(cs == s){
                if(last) lind[ind]++;
                if(first) linf[ind]++;
//                cout <<dec << i << ' ' <<  cs << endl;
                put(primen[ind][k]);
                k++;
            }
            else nprime[i] = true;
        }
    }
#if 0
    for(int i = 0; i < 10; i++){
        cout << i << ' ' << cind[i] << endl;
        for(int j = 0; j < cind[i]; j++){
            cout << j << ": ";
            for(int k = 0; k < 5; k++){
                cout << primen[i][j][k];
            }
            cout << endl;
        }   
        cout << endl;
    }
#endif
}

int lesst = 0;
bool check(){
    lesst++;
    int b = tab[0][1] << 16 | tab[1][1] << 12 | tab[2][1] << 8 | tab[3][1] << 4 | tab[4][1];
    if(!st[b]) return false;
    b = tab[0][3] << 16 | tab[1][3] << 12 | tab[2][3] << 8 | tab[3][3] << 4 | tab[4][3];
    if(!st[b]) return false;

    b = tab[1][0] << 16 | tab[1][1] << 12 | tab[1][2] << 8 | tab[1][3] << 4 | tab[1][4];
    if(!st[b]) return false;
    b = tab[3][0] << 16 | tab[3][1] << 12 | tab[3][2] << 8 | tab[3][3] << 4 | tab[3][4];
    if(!st[b]) return false;
    
    return true;
}

void dfs(int d){
    int tc = tab[0][0];
#if 0
    if (d==7) {
        cout << "step " <<  d << ' ' <<  tc << ' ' << cind[tc] << endl;
        print();
    }
#endif
    switch(d){
        case 0: 
            for(int i = 0; i <linf[tc]; i++){
                for(int j = 1; j < 5; j++){
                    tab[0][j] = primef[tc][i][j];
                }
                dfs(d+1);
            }
            break;
        case 1: 
            for(int i = 0; i <linf[tc]; i++){
//                cout << "cur " << i << endl;
                for(int j = 1; j < 5; j++){
                    tab[j][0] = primef[tc][i][j];
                }
                dfs(d+1);
            }
            break;
        case 2:
            tc = tab[4][0];
            for(int i = 0; i <cind[tc]; i++){
                if(primen[tc][i][4] == tab[0][4]){
                    for(int j = 1; j <= 3; j++){
                        tab[4-j][j] = primen[tc][i][j];
                    }
                    dfs(d+1);
                }
            }
            break;
        case 3:
            for(int i = 0; i <cind[tc]; i++){
                if(primen[tc][i][2] == tab[2][2]){
                    for(int j = 1; j < 5; j++){
                        tab[j][j] = primen[tc][i][j];
                    }
                    dfs(d+1);
                }
            }
            break;
        case 5: 
            tc = tab[0][4];
            for(int i = 0; i < lind[tc]; i++){
                if(primel[tc][i][4] == tab[4][4]){
                    for(int j = 1; j < 4; j++){
                        tab[j][4] = primel[tc][i][j];
                    }
                    dfs(d+1);
                }
            }
            break;
        case 6:
            tc = tab[2][0];
            for(int i = 0; i < cind[tc]; i++){
                if(primen[tc][i][2] == tab[2][2] && primen[tc][i][4] == tab[2][4]){
                    tab[2][1] = primen[tc][i][1];
                    tab[2][3] = primen[tc][i][3];
                    dfs(d+1);
                }
            }
//            break;
        case 7: 
            tc = tab[0][2];
            for(int i = 0; i < cind[tc]; i++){
                if(primen[tc][i][2] == tab[2][2] && primen[tc][i][4] == tab[4][2]){
                    tab[1][2] = primen[tc][i][1];
                    tab[3][2] = primen[tc][i][3];
                    dfs(d+1);
                }
            }
            break;
        case 4:
            tc = tab[4][0];
            for(int i = 0; i < lind[tc]; i++){
                if(primel[tc][i][4] == tab[4][4]){
                    int j = 1;
                    for(; j < 4; j++){
                        tab[4][j] = primel[tc][i][j];
                    }
                    dfs(d+1);
                }
            }
            break;
        case 8:
            if(check()){
 //               cout << "res********\n";
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < 5; j++){
                        ans[has].a[i][j] = tab[i][j];
                    }
                }
                has++;
            }
    }
}

int main(){
    in >> s >> tab[0][0];
//    cout << s << ' ' << tab[0][0] << endl;

    primes();
    dfs(0);
    if(!has){
        out << "NONE\n";
        return 0;
    }
    sort(ans,ans+has);
    for(int i = 0; i < has; i++){
        if(i != 0) out << endl;
        for(int j =0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                out << ans[i].a[j][k];
            }
            out << endl;
        }
    }
    cout << lesst << endl;
    cout << "has "  << has << endl;
}
