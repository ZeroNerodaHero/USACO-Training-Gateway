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
int l[5];
int mx[5],my[5];

void print(){
    //for(int i = 0; i < 26; i++) cout << int(ar[i]) << ' '; cout << endl;
    cout << "string " <<  ar << endl;
}

int dfs(int ch){
    int& x = dp[l[0]][l[1]][l[2]][l[3]][l[4]];

    if(x > 0) return x;
    if(l[0] == 5 && l[1] == 5 && l[2] == 5 && l[3] == 5 && l[4] == 5){
        print();
        return 1;
    }    

    int v = 0;
    while(visited[ch]) ch++;

//    cout << l[0] << l[1] << l[2]<< l[3] << l[4] << ": " << ch <<endl;
    visited[ch] = true;
    for(int i = 0; i < 5; i++){
        if(l[i] < 5 && (i == 0 || l[i] < l[i-1]) && mx[i] < ch && my[l[i]] < ch){
            ar[l[i]+5*i] = char(ch+'A');
            int ox = mx[i], oy = my[l[i]];
            mx[i] = ch;
            my[l[i]] = ch;
            l[i]++;
            v += dfs(ch+1);
            mx[i] = ox;
            l[i]--;
            my[l[i]] = oy;
        }
    }
    visited[ch] = false;
    x = v;
    return x;
}

int main(){
    int c;
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    c = dfs(0);
    cout <<"count: " <<  c << endl;

#if 0
    // prefix "A"
    visited[0] = true;
    visited[3] = true;
    ar[0] = 'A';
    ar[1] = 'D';
    l[0] = 2;
    m[0] = 3;
    memset(dp, 0, sizeof(dp));
    c = dfs(0);
    cout <<"count: " <<  c << endl;
#endif
}
