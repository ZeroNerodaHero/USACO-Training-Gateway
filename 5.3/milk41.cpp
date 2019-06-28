/*
ID: billy
PROG: milk4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
std::ifstream in("milk4.in");
std::ofstream out("milk4.out");

int Q;
int P;
int t[100];
bool dp[20001];
vector<int> c;

void print1(){
    for(auto &i : c){
        cout << i << ' ';
    }
    cout << endl;
}

bool check(){
    dp[0] = true;
    for(int i = 1; i <= Q; i++){
        dp[i] = false;
        for(auto &j: c){
            if(i-j >= 0 && dp[i-j]){
                dp[i] = true;
                break;
            }
        }
    }   
 //   cout << dp[Q] << endl;
    return dp[Q];
}

bool combo(int s, int e){
    if(c.size() == e){
 //           print1();
        if(check()){
            return true;
        }
        return false;;
    } 
    if(s == P) return false;
    c.push_back(t[s]);
    if(combo(s+1,e)) return true;
    c.pop_back();
    if(combo(s+1,e)) return true;
}

void print(){
    for(int i = 0; i < P; i++){
        cout << t[i] << ' ';   
    }
    cout << endl;
}
int main(){
    in >> Q >> P;
    for(int i = 0; i < P; i++){
        in >> t[i];
    }
    sort(t,t+P);
//    print();
    for(int i = 1; i <= P; i++){
       if(combo(0,i)){
            break;
       }
    }
    out << c.size();
    for(auto &i : c){
        out << ' ' << i;
    }  
    out << endl;
}
