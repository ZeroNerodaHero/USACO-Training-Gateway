/*
ID: billyz43
PROG: contact
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
std::ifstream in("contact.in");
std::ofstream out("contact.out");
std::map<string,int> m;

struct cnum{
    string first;
    int second;
    cnum(string first, int second): first(first),second(second) {}
    cnum() {}
};

bool cmp(cnum& a, cnum& b){
    if(a.second == b.second){
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size(); 
        for(int i = 0; i < a.first.size();i++){
            if(a.first[i] != b.first[i]){
                return a.first[i] < b.first[i];
            }
        }
    }
    return a.second > b.second;   
}

int main(){
    int A,B,N;
    string seq,tmp;
    in >> A >> B >> N >>seq;
    while(in>>tmp){
        seq += tmp;
    }
    cout << seq << endl;
    if(seq.size() == 1) B = N = 1;

    for(int i = A; i<=B; i++){
        for(int j = 0; j <= seq.size()-i;j++){
            string var = "";
            for(int k = j; k < j+i; k++){
                var += seq[k];
            }
            m[var]++;
        }
    }

    cnum all[m.size()];
    int c = 0;
    for(auto &it:m){
        all[c++] = cnum(it.first,it.second);
    }

    sort(all,all+m.size(),cmp);

    int lens = -1, tot = 0, lsize = 0;
    for(int i = 0; i < m.size(); i++){
        if(all[i].second != lens){
            tot++;
            if(tot > N) break;
            if(tot > 1) out << endl;
            out << all[i].second << endl << all[i].first;
            lens = all[i].second;
            lsize = 1;
        } else{
            if(lsize == 6){
                lsize = 0;
                out << endl << all[i].first;
            } else{
                out << " " << all[i].first;
            }
            lsize++;
        }
    }
    out << endl;
}

