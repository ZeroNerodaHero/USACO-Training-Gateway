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
int m[12][1<<12];

struct cnum{
    int v, b, c;
    bool operator< (const cnum& o) const{
        if(c == o.c){
            if(b != o.b) return b < o.b;
            return v < o.v; 
        }
        return c > o.c;
    }
};

ostream& operator<< (ostream& os, cnum& o){
    for(int i = o.b-1; i >= 0; i--){
        if(o.v & (1 << i)) os << '1';
        else os << '0';  
    }
    return os;
}

void print(cnum ar[], int size){
    for(int i = 0; i < size; i++){
        cout << ar[i].c << ' ' << ar[i].b << ' ' << ar[i].v << ' ' << ar[i]<< endl;
    }
}


int main(){
    int A,B,N,W,seq;
    char tmp;
    in >> A >> B >> N;
    for(int i = 0; ; i++){
        in >> tmp;
        if (in.eof()) break;
        seq <<= 1;
        if(tmp == '1') seq |= 1;
        for(int j = A-1; i >= j && j < B; j++){
            W = seq&((1<<(j+1))-1);
            m[j][W]++;
//            cout << j << " xx " <<W << endl;
        }
    }

    cnum all[8192];
    int c = 0;
    for(int i = A-1; i < B; i++){
        for(int j = 0; j < (1<<(i+1)); j++){
            if(m[i][j] > 0){
                all[c].v = j;
                all[c].b = i+1;
                all[c++].c = m[i][j];
            }
        }
    }

    sort(all,all+c);
//    print(all,m.size());

    int lens = -1, tot = 0, lsize = 0;
    for(int i = 0; i < c; i++){
        if(all[i].c != lens){
            tot++;
            if(tot > N) break;
            if(tot > 1) out << endl;
            out << all[i].c << endl << all[i];
            lens = all[i].c;
            lsize = 1;
        } else{
            if(lsize == 6){
                lsize = 0;
                out << endl << all[i];
            } else{
                out << " " << all[i];
            }
            lsize++;
        }
    }
    out << endl;
}

