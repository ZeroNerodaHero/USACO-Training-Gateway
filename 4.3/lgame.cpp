/*
ID: billyz43
PROG: lgame
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
std::ifstream in("lgame.in");
std::ifstream din("lgame.dict");
std::ofstream out("lgame.out");

int m[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};

struct node{
    node *next[26];
    bool end;
    node(){
        end = false;
        for(int i = 0; i < 26; i++){
            next[i] = nullptr;
        }
    }
};

node head,*root = &head;   
string s;

void insert(string& str){
    node * p = root;
    for(int i = 0; i < str.size(); i++){
        if(p->next[str[i]-'a'] == nullptr){
            p->next[str[i]-'a'] = new node;
        }
        p = p->next[str[i]-'a'];
    }
    p->end = true;
}

int res = 0;
set<string> v;
    
void dfs1(node *p,string s1,string s2,string& s0,int sc0){
    if(p == nullptr) return;
    if(p->end){
        int score = sc0;
        for(int i = 0; i < s2.size(); i++){
            score += m[s2[i]-'a'];
        }
        if(res < score){
            res = score;
            v.clear();
        }
        if(res == score){
            if(s2.compare(s0) < 0){
                v.insert(s2+' '+s0);
            } else{
                v.insert(s0+' '+s2);
            }
        }
    }

    for(int i = 0; i < s1.size(); i++){
        dfs1(p->next[s1[i]-'a'],s1.substr(0,i)+s1.substr(i+1),s2+s1[i],s0,sc0);
    }
}

void dfs(node *p,string s1,string s2){
    if(p == nullptr) return;
    if(p->end){
        int score = 0;
        for(int i = 0; i < s2.size(); i++){
            score += m[s2[i]-'a'];
        }
        if(res < score){
            res = score;
            v.clear();
        }
        if(res == score){
            v.insert(s2);
//            cout << s2 << endl;
        }
        if(s2.size() <= s.size()/2) dfs1(root,s1,"",s2,score);
    }
//    cout << s1 << ' ' << s2 << endl;

    for(int i = 0; i < s1.size(); i++){
        dfs(p->next[s1[i]-'a'],s1.substr(0,i)+s1.substr(i+1),s2+s1[i]);
    }
}

int main(){
    string dict;
    while(true){
        din >> dict;
        if(dict == ".") break;
//        cout << dict << endl;
        insert(dict);
    } 
    in >> s;
    dfs(root,s,"");   
    out << res << endl;
    for(auto& i: v){
        out << i << endl;
    }
}
