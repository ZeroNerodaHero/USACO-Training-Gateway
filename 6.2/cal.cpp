/*
ID: billyz43
PROG: calfflac
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("calfflac.in");
std::ofstream out("calfflac.out");
string s = "",tmp;
int longest = 0;
int al, ar;
int t;
int ind[20000];

void lower(){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] -'A' + 'a';
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            ind[t] = i;
            s[t] = s[i];
            t++;
        }
    }
}

void check1(int mid,int con){
    int len = 0;
    int l = mid, r = mid+con;
    if(con == 0){
        l = mid-1;
        r = mid+1;
        len =1;
    }
    while(l >= 0 && r < t && s[l] == s[r]){
        //cout << l << ' ' << r << endl;
        l--;r++;
        len+=2;
        //cout << "cur len " << len << endl;
    }
//   cout << longest << endl;
    if(longest < len){
        longest = len;
//        cout << l << ' ' << s[l] << "\t:\t" << el << ' ' << s[l+el] << endl;;
        al = l;
        ar = r;
    }
}

void print(){
    int s = ind[al], l= ind[ar] - ind[al] +1;
    while(l> 0){
        if(l < 79){
            out << tmp.substr(s,l) << endl;
            l = 0;
        } else{
            out << tmp.substr(s,79) << endl;;
            s += 79;
            l -= 79;
        }
    }
}

int main(){
    while(getline(in,tmp)){
        s+= tmp + '\n';
    } 
    tmp = s;
    lower();
    for(int i = 0; i < s.size(); i++){
        check1(i,0);
        check1(i,1);
    }
    out << longest << endl;
    al++, ar--;
    //print();
    out << tmp.substr(ind[al],ind[ar]-ind[al]+1) << endl;;
}
