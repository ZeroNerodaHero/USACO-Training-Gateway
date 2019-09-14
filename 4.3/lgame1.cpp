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
void dfs(int n,node *p,int score, bool first, int len){
    if(p == nullptr) return;
    if(p->end){
        if(res < score){
            res = score;
 //           v.clear();
 //           v.push_back();
        } else if(res == score){
 //           v.push_back();
        }
        if(first){
            dfs(n,root,score,false,n);
        }
    }

    for(int i = 0; i < n; i++){
        swap(s[0],s[n-1]);
        dfs(n-1,p->next[s[n-1]-'a'],score+m[s[n-1]],first,len);
        swap(s[0],s[n-1]);
    }
}

int main(){
    string dict;
    while(true){
        din >> dict;
        if(dict == ".") break;
        cout << dict << endl;
        insert(dict);
    } 
    in >> s;
    dfs(s.size(),root,0,true,0);   
}
