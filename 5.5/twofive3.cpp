/*
ID: billy
PROG: hidden
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;
std::ifstream in("hidden.in");
std::ofstream out("hidden.out");

bool visited[25];
char ar[28];
int dp[6][6][6][6][6];

void print(){
    //for(int i = 0; i < 26; i++) cout << int(ar[i]) << ' '; cout << endl;
    cout << "string " <<  ar << endl;
}

int dfs(int a,int b,int c,int d,int e,int ch){
    if(dp[a][b][c][d][e] > 0) return dp[a][b][c][d][e];
//    cout << a << b << c << d << e << ' ' << char('a'+ch) <<endl;
    if(a == 5 && b == 5 && c == 5 && d == 5 && e == 5){
        print();
        return 1;
    }    

    int v = 0;
    while(visited[ch]) ch++;
    visited[ch] = true;

    if(a < 5){
        ar[a] = char(ch+'a');
        v += dfs(a+1,b,c,d,e,ch+1);
    }
    if(b < 5 && b < a){
        ar[5+b] = char(ch+'a');
         v+= dfs(a,b+1,c,d,e,ch+1);
    }
    if(c < 5 && c < b){
        ar[10+c] = char(ch+'a');
        v+= dfs(a,b,c+1,d,e,ch+1);
    }
    if(d < 5 && d < c){
        ar[15+d] = char(ch+'a');
        v+= dfs(a,b,c,d+1,e,ch+1);
    }
    if(e < 5 && e < d){
        ar[20+e] = char(ch+'a');
        v+= dfs(a,b,c,d,e+1,ch+1);
    }

    visited[ch] = false;
    dp[a][b][c][d][e] = v;
    return dp[a][b][c][d][e];;
}

int main(){
    int c = dfs(0,0,0,0,0,0);
    cout << c << endl;
}
