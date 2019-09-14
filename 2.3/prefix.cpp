/*
ID: billyz43
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
std::ifstream in("prefix.in");
std::ofstream out("prefix.out");
unordered_set<string> dict;
int bx;
std::string seq;

struct node{
    node * c[26];
    bool end;
    node(){
        end = false;
        for(int i = 0; i < 26; i++){
            c[i] = nullptr;
        }
    }
};
node root;

void insert(string &s){
    node * p = &root;

    for(int i = 0; i < s.size(); i++){
        int id = s[i]-'A';
        if(p->c[id] == nullptr)
            p->c[id] = new node;
        p = p->c[id];
    }
    p->end = true;
}

bool find(string s){
    node * p = &root;

    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'A';
        if(p->c[id] == nullptr) return false;
        p = p->c[id];
    }
    return p->end;
}

int dfs(int start){
    if(start ==seq.size()) return 0;
    int big = 0;
    for(int i = 1; i <= bx; i++){
        //cout <<i << " " << start<<" " << start+i<< "" <<seq.substr(start,i) << endl;
        if(start+i <= seq.size() && dict.find(seq.substr(start,i)) != dict.end())
            big = max(big,i+dfs(start+i));
    }
    return big;
}

bool dp[200001];
int predp(){
    int longest = 0;
    dp[0] = true;
    for(int i = 0; i < seq.size(); i++){
        if(!dp[i]) continue;
        for(int l = 1; l <= bx; l++){
            //if(i+l <= seq.size()&& !dp[i+l] && dict.find(seq.substr(i,l)) != dict.end()){
            if(i+l <= seq.size()&& !dp[i+l] && find(seq.substr(i,l))){
                dp[i+l] = true;
                longest = max(longest,i+l);
            }
        }
    }
    return longest;
}

int main(){
    string read;
    in >> read;
    while(read != "."){
        bx = max(bx,int(read.size()));
        //dict.insert(read);
        insert(read);
        in >> read;
    }
    ///*
    while(in >> read){
        seq += read;
    }
    //std::cout << seq << endl;
    //*/
    //seq = "ABABACABAABC";
    out << predp() << endl;
}


//generate a list
