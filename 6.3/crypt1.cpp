/*
ID: billyz43
PROG: cryptcow
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>
using namespace std;
std::ifstream in("cryptcow.in");
std::ofstream out("cryptcow.out");
string s = "Begin the Escape execution at the Break of Dawn";
const int  MAXN = ((1<<19)+7);
int D;

struct node{
    node * next;
    char ch[80];
    node(){
        next = nullptr;
    }
};
node * htable[MAXN];
node ht[MAXN];
int C=0;
node * get()
{
    if(C < MAXN) {
        return &ht[C++];
    } else{
        return new node;
    }
}

int hasher(string& str){
    unsigned int hash = 5381^str.size();
    int c = 0;


    for(int i =0; i < str.size(); i++){
        c = str[i];
        hash = ((hash << 5) + hash) + c;
    }
//    cout << hash << endl;

    return hash%MAXN;
}

bool find(string& a){
    int j = hasher(a);    
    node * tmp = htable[j];;
    while(tmp != nullptr){
        if(tmp->ch[0] == a.size()){
            int i = 0;
            for(; i < a.size(); i++){
                if(tmp->ch[i+1] != a[i]) break;
            }
            if(i == a.size()){
                return true;
            }
//                cout << " true\n";;
        }
        tmp = tmp->next;
    }
    tmp = get();
    tmp->ch[0] = a.size();
    for(int i = 1; i <= a.size(); i++){
        tmp->ch[i] = a[i-1];
    }    
    tmp->next = htable[j];
    htable[j] = tmp;
    return false;
}



bool dfs(string& cur, int d,int t){
    if(t == 0){
        if(cur == s){
            D = d;
            return true;
        }
        return false;
    }
    int ac[t],ao[t],aw[t];
    int c = 0,o = 0,w = 0;
    for(int i = 0; i < cur.size(); i++){
        if(cur[i] == 'C') ac[c++] = i; 
        if(cur[i] == 'O'){
            if(c == 0){
                //cout << "no c\n";
             //    return false;;
            }
             ao[o++] = i; 
        }
        if(cur[i] == 'W'){
            if(w == t-1 && (c != t || o != t)){
                //cout << t << endl;
                //cout << c << ' ' << o << ' ' << w << endl;
                //cout << "no w\n";
                 return false;
            }
            aw[w++] = i; 
        }
    }    
    if(w != t) return false;
    cout << cur << endl;
    if(find(cur)){
//        cout << "find " << cur << endl;
        return false; 
    }

    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            if(ac[i] > ao[j]) continue;
            for(int k = 0; k < t; k++){
                if(ao[j] < aw[k]){
                    string tmp = cur.substr(0,ac[i])+cur.substr(ao[j]+1,aw[k]-ao[j]-1)+cur.substr(ac[i]+1,ao[j]-ac[i]-1)+cur.substr(aw[k]+1);
                    if(dfs(tmp,d+1,t-1)) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    string c;
    getline(in,c);
//    in >> noskipws;
//    in  >> c;
    int t = c.size() - s.size();
    bool ret = false;
    if(t%3 == 0){
        ret = dfs(c,0,t/3);
    } 
    out << ret << ' ' << D << endl;
}
