/*
ID: billy
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

struct node{
    int a[5];
};

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
vector<node> pf[10],pd[10][10],p2[10][10],pl[10][10][10];

vector<mat> ans;
mat tab;
bool st[10][10][10][10][10];;

void print(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            out << tab.a[i][j];
        }
        out << endl;
    }
}

void inline put(int a[]){
    st[a[0]][a[1]][a[2]][a[3]][a[4]] = true;
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
    for(int i = 10001; i < 99999; i++){
        if(nprime[i] == 0){
            int x = i;
            node n;
            int c = 0;
            for(int j = 4; j >= 0; j--){
                n.a[j] = x%10;
                c += n.a[j];
                x/=10;
            }
            if(c != s) continue;
            put(n.a);
            p0[n.a[0]].push_back(n);
            p2[n.a[2]].push_back(n);
            p3[n.a[1]][n.a[2]][n.a[3]].push_back(n);
            if(((n.a[0]&1)!=0) && (n.a[0]!= 5)) p22[n.a[2]].push_back(n);
        }
    }
#if 0
    for(int i = 0; i < 10; i++){
        cout << i << ": " << p2[i].size() << endl;
        for(auto& j: p0[i]){
            //for(int k = 0; k < 5; k++){ cout << j.a[k]; } cout << endl;
        }    
    }
#endif
}

int lesst = 0;
bool check(){
    lesst++;
    return  st[tab.a[0][0]][tab.a[1][0]][tab.a[2][0]][tab.a[3][0]][tab.a[4][0]] &&
            st[tab.a[0][4]][tab.a[1][4]][tab.a[2][4]][tab.a[3][4]][tab.a[4][4]] &&
            st[tab.a[0][0]][tab.a[0][1]][tab.a[0][2]][tab.a[0][3]][tab.a[0][4]] &&
            st[tab.a[4][0]][tab.a[4][1]][tab.a[4][2]][tab.a[4][3]][tab.a[4][4]];
}

void dfs(int d){
    int tc = tab.a[0][0];
    int tc1,tc2,tc3;
#if 0
    if (d==7) {
        cout << "step " <<  d << ' ' <<  tc << ' ' << cind[tc] << endl;
        print();
    }
#endif
    switch(d){
        case 0: 
            for(auto& i: p0[tc]){
                for(int j = 1; j < 5; j++){
                    tab.a[j][j] = i.a[j];
                }
                dfs(d+1);
            }
            break;
        case 1: 
            tc = tab.a[2][2];
//            for(auto& i: p22[tc]){
            for(auto& i: p2[tc]){
                if(((i.a[0]&1)==0) || i.a[0] == 5) continue;
                for(int j = 0; j < 5; j++){
                    tab.a[4-j][j] = i.a[j];
                }
                dfs(d+1);
            }
            break;
        case 2:
            tc = tab.a[2][2];
            for(auto& i: p2[tc]){
                for(int j = 0; j < 5; j++){
                    tab.a[2][j] = i.a[j]; 
                }
                dfs(d+1);
            }
            break;
        case 3:
            tc = tab.a[2][2];
            for(auto& i: p2[tc]){
                for(int j = 0; j < 5; j++){
                    tab.a[j][2] = i.a[j]; 
                }
                dfs(d+1);
            }
            
            break;
        case 4: 
        case 6:
            tc1 = tab.a[d-3][1];
            tc2 = tab.a[d-3][2];
            tc3 = tab.a[d-3][3];
            for(auto& i: p3[tc1][tc2][tc3]){
                tab.a[d-3][0] = i.a[0];
                tab.a[d-3][4] = i.a[4];
                dfs(d+1);
            }
            break;
        case 5:
        case 7: 
            tc1 = tab.a[1][d-4];
            tc2 = tab.a[2][d-4];
            tc3 = tab.a[3][d-4];
            for(auto& i: p3[tc1][tc2][tc3]){
                tab.a[0][d-4] = i.a[0];
                tab.a[4][d-4] = i.a[4];
                dfs(d+1);
            }
            break;
        case 8:
            if(check()){
                ans.push_back(tab);
            }
    }
}

int main(){
    in >> s >> tab.a[0][0];
//    cout << s << ' ' << tab.a[0][0] << endl;

    primes();
    dfs(0);
    if(ans.size()==0){
        out << "NONE\n";
        return 0;
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) out << endl;
        for(int j =0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                out << ans[i].a[j][k];
            }
            out << endl;
        }
    }
//    cout << lesst << endl;
//    cout << "has "  << ans.size() << endl;
}
