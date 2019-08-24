/*
ID: billy
PROG: hidden
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;
std::ifstream in("hidden.in");
std::ofstream out("hidden.out");

struct suff{
    int ind;
    int rnk[2];
    bool operator < (const suff& o) const{
        if(rnk[0] == o.rnk[0]){
            if(rnk[1] == o.rnk[1]) return ind < o.ind;
            return rnk[1] < o.rnk[1];
        }
        return rnk[0] < o.rnk[0];
    }
};

int L;
string s;
suff sar[100000];

void print(){
    for(int i = 0; i < L; i++){
        cout << sar[i].ind << ' ';
    }
    cout << "\n\t";
    for(int i = 0; i < L; i++){
        cout << sar[i].rnk[0] << ' ';
    }
    cout << "\n\t";
    for(int i = 0; i < L; i++){
        cout << sar[i].rnk[1] << ' ';
    }
    cout << endl << endl;
}

int suff(){
    for(int i = 0; i < L; i++){
        sar[i].ind = i;
        sar[i].rnk[0] = s[i];        
        sar[i].rnk[1] = s[i+1];        
    }

    sort(sar,sar+L);
  //  print();
    for(int w = 4; w < L; w *= 2){
        int loc[L];
        //sar[0].rnk[0] = 0;
        int pre = sar[0].rnk[0];
        loc[sar[0].ind] = 0;
        for(int i = 1; i < L; i++){
            if(pre == sar[i].rnk[0] && sar[i].rnk[1] == sar[i-1].rnk[1]) sar[i].rnk[0] = sar[i-1].rnk[0];
            else{
                pre = sar[i].rnk[0];
                sar[i].rnk[0] = sar[i-1].rnk[0]+1;
            }
            loc[sar[i].ind] = i;
        }
        
        for(int i = 0; i < L; i++){
            int t = sar[i].ind+w/2;
            if(t >= L){
                t -= L;
            }
            sar[i].rnk[1] = sar[loc[t]].rnk[0];
        }
        sort(sar,sar+L);
//        print();
    }   
    return sar[0].ind;
}

int main(){
    string a;
    in >> L;
    int line = L;
    while(line > 0){
        in >> a;
        s += a;
        line -= 72;
    }
    s += s;
    int ans = suff();
    out << ans << endl; 
}
