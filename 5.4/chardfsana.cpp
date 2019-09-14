/*
ID: billyz43
PROG: charrec
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define INF 0x6f6f
using namespace std;
std::ifstream in("charrec.in");
std::ofstream out("charrec.out");
std::ifstream fin("font.in");
int N;
int err[1200],p[1200];
char m[1200];
char c[100];
char font[27][20][21];
char line[1200][21];
int d[27][20][1200];
const char ss[] = " abcdefghijklmnopqrstuvwxyz";
int dp[1200];

int diff19(int s, int l,char& ch){
    int sm = 2000;
    for(int i = 0; i < 27; i++){
        int t = 0;
        for(int j = s, k = 0; k < 19; k++,j++){
            t += d[i][k][j];
        }
   //     cout << ss[i] << " total " << t << endl;
        for(int rem = 18; rem >= 0; rem--){
            t += d[i][rem+1][s+rem] - d[i][rem][s+rem]; 
            if(t < sm){
 //               cout << i << " sm " << sm << " t " << t << endl;
                sm = t;
                ch = ss[i];
            }
        }
    }
    return sm;
}

int diff21(int s, int l,char& ch){
    int sm = 2000;
    for(int i = 0; i < 27; i++){
        int t = 0;
        for(int j = 0, k = s; j < 20; j++, k++){
            t += d[i][j][k];
        }
        for(int j = 19; j >= 0; j--){
            t += d[i][j][s+j+1] - d[i][j][s+j];
            if(t < sm){
                sm = t;
                ch = ss[i];
            }
        } 
    }
    return sm;
}

int diff(int s, int l,char& ch){
    if(l == 19) return diff19(s,l,ch);
    else if(l == 21) return diff21(s,l,ch);
    int sm = 2000;
    for(int i = 0; i < 27; i++){
        int dd = 0;
        for(int j = s, k = 0; k < 20; j++,k++){
            dd += d[i][k][j];
        }
        if(sm > dd){
            sm = dd;
            ch = ss[i];
        }
    }
    return sm;
}

void print(){
    for(int i = 0; i < N; i++){
        
        cout << line[i] << endl;
    }
}

void dfs(int s){
    dp[s]++;
    for(int i = 19; i < 22; i++){
        if(s + i <= N){
            //bool dodfs = false;
            //if(err[s+i] == INF) dodfs = true;
            //cout << "s " << s  << ' '  <<s+i << endl;
            char ch;
            int r = diff(s,i,ch);
            //cout << "err " << err[s+i] << "-" << err[s] <<' '<< r<< endl;;
            if(err[s+i] > err[s] + r) {
                err[s+i] = err[s]+r;
                m[s+i] = ch;
                p[s+i] = s;
                //if(dodfs) dfs(s+i);
                dfs(s+i);
            }
        }
    }
}


int main(){
    in >> N;
    int size;
    fin >> size;
    for(int i = 0; i < 27; i++){
        for(int j = 0; j < 20; j++){
            fin >> font[i][j];
 //           cout << font[i][j] << endl;
        }
    }   

    for(int i = 0; i < N; i++){
        in >> line[i];
    }
//    print();

    for(int i = 0; i < 27; i++){
        for(int j = 0; j < 20; j++){
            for(int l = 0; l < N; l++){           
                for(int k = 0; k < 20; k++){
//                    cout << font[i][j][k] << " line " << line[l][k] << endl;
                    if(font[i][j][k] != line[l][k]){
                        d[i][j][l]++;
                    }
                }
 //               cout << "diff " << i << ' '<< j << ' ' << l << ' ' <<  d[i][j][l] << endl;;
            }
        }
    }   
    for(int i = 1; i <= N; i++) err[i] = INF;

    dfs(0);

    int i = 90;
    c[i] = '\0';
    int j = N;
    while(j > 0){
        c[--i] = m[j];
        j = p[j]; 
    }
    out << c+i << endl; 
    
    for(int i = 0; i < N; i++){
        cout << i << ' ' << dp[i] << endl;
    }
}
