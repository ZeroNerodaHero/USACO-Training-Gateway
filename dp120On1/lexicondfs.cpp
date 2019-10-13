/*
ID: billyz43
PROG: lexicon
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <cmath>
#define INF 160000
std::ifstream in("lexicon.in");
std::ofstream out("lexicon.out");
using namespace std;
int W, L;
string msg;
unordered_set<string> dict;
int sm = INF;
int st=INF,ed=0;

bool check(string s){
    if(s.size() == 0) return true;
    for(int i = st; i <= ed; i++){
        string tmp = s.substr(0,i);
        if(dict.find(tmp) != dict.end()){
            return check(s.substr(i));
        }
    }
    return false;
}

void dfs(string s, int p,int d){
    if(p == msg.size()){
//cout << s << ' ' << p << ' ' << d << endl;
        if(sm <= d) return;
        if(check(s)){
            sm = d;
        }
        return;
    }

    dfs(s+msg[p],p+1,d);
    dfs(s,p+1,d+1);
}

int main(){
    in >> W >> L >> msg;
    for(int i = 0; i < W; i++){
        string s;
        in >> s;
        dict.insert(s);
        if(st > s.size()) st = s.size();
        if(ed < s.size()) ed = s.size();
    }
    string s = "";
    dfs(s,0,0);
    out << sm << endl;
}
