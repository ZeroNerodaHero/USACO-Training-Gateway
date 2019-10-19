/*
ID: billyz43
PROG: impster
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("impster.in");
std::ofstream out("impster.out");
using namespace std;
int B, E, init;
int ex[101];
bool used[1<<16];

struct str{
    int st, cnt;
    str(int st, int cnt): st(st), cnt(cnt) {};
};

int countb(int a){
    int cnt = 0;
    while(a > 0){
        cnt++;
        a = a&(a-1);
    }
    return cnt;
}

int convert(string& s){
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret <<= 1;
        if(s[i] == '1') ret |= 1;
    } 
    return ret;
}

void con(int best){
    for(int i = B-1; i >= 0; i--){
        out << ((best>>i)&1);
    }   
    out << endl;
}   

void sl(){
    queue<str> q;
    int best, bestb = 20, mincnt = 20;
    for(int i = 0; i < E; i++){
        q.push(str(ex[i],0));
    }

    while(!q.empty()){
        str tmp = q.front();
        q.pop();

        if(tmp.st == init){
            best = tmp.st;
            mincnt = tmp.cnt;
            break;
        } else{
            int diff = countb((tmp.st^init));
            if(diff < bestb){
                best = tmp.st;
                bestb = diff;
                mincnt = tmp.cnt;
            } else if(diff == bestb && tmp.st < best && mincnt == tmp.cnt){
                best = tmp.st;
            }
        }

        for(int i = 0; i < E; i++){
            int ch = (tmp.st^ex[i]);
            if(!used[ch]){
                used[ch] = true;
                q.push(str(ch,tmp.cnt+1)); 
            }
        }    

    }
    out << mincnt << endl;
    con(best);
}

int main(){
    string tmp;
    in >> B >> E >> tmp;
    init = convert(tmp);

    for(int i = 0; i < E; i++){
        in >> tmp;
        ex[i] = convert(tmp);
    }      
    if(E == 1){
        int a = countb(ex[0]^init);
        int b = countb(init);
        
        if(a < b){  
            out << 2 << endl;
            con(ex[0]);
        } else{
            out << 1 << endl;
            con(0);
        }
        return 0;

    }
    sl();
}
