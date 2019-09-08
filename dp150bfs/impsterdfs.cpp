/*
ID: billy
PROG: impster
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
#define INF 9999
std::ifstream in("impster.in");
std::ofstream out("impster.out");
using namespace std;
int B, E;
int g,gans,ans = 1000,gdif=20;
int id[101];

int countb(int a){
    int cnt = 0;
    while(a > 0){
        cnt++;
        a = a&(a-1);
    }
    return cnt;
}

void dfs(int tot, int s, int i){
    if(i == E){
        int a = countb(tot^g);
        if(gdif > a){
            gdif = a;
            gans = tot;
            ans = s;
        } else if(gdif == a){
            if(s < ans){
                ans = s;    
                gans = tot;
            } else if(ans == s){
                if(tot < gans) gans = tot;
            }
        }
        return;
    }
    dfs(tot^id[i],s+1,i+1);
    dfs(tot,s,i+1);
}

int convert(string& s){
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret <<= 1;
        if(s[i] == '1') ret |= 1;
    } 
    return ret;
}

void outp(int a){
    for(int i = B-1; i >= 0; i--){
        out << ((a>>i)&1);
    }
    out << endl;
}

void print(){
    for(int i = 0; i < E; i++){
        cout << id[i] << endl;
    }
}

int main(){
    string tmp;
    in >> B >> E >> tmp;
    g = convert(tmp);

    for(int i = 0; i < E; i++){
        in >> tmp;
        id[i] = convert(tmp);
    }      
    if(E == 1){
        int a = countb(id[0]^g);
        int b = countb(g);
        
        if(a < b){  
            out << 2 << endl;
            outp(id[0]);
        } else{
            out << 1 << endl;
            outp(0);
        }
        return 0;

    }
    dfs(0,0,0);

//    print();
    
//    cout << ans << endl << gans<< endl;
    out << ans-1 << endl;
    outp(gans);
}
