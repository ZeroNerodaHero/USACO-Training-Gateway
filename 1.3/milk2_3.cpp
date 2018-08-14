/*
ID: NomNom
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct event{
    int s, e;
    event(int s=0, int e=0): s(s), e(e){};
    bool operator < (const event &o) const{
        if(s != o.s) return s < o.s;
        return e > o.e;
    }
};

int main(){
    ifstream in("milk2.in");
    ofstream out("milk2.out");

    int N;
    in >> N;
    event v[2*N];
 
    cout << "N:\t" <<  N << '\n';

    for(int i = 0; i < N; i++){
        in >> v[i].s; v[i].e = 1;
        in >> v[i+N].s; v[i+N].e = -1;
    }

    sort(v,v+2*N);

    bool done = true;
    int istart,il, ml;
    ml = 0;
    il = 0;
    int nmilk = 0;

    for(int i = 0; i < 2*N; ++i){
        nmilk += v[i].e;
        if(nmilk == 0 && !done){
            ml = max(ml, v[i].s - istart);
            istart = v[i].s;
        }
        else{
            if(nmilk > 0 && done){
                if(i != 0){
                    il = max(il, v[i].s - istart);
                }
                istart = v[i].s;
            }
        } 
        done = nmilk == 0;
    }
    cout << ml << ' ' << il << endl;
    out << ml << ' ' << il << endl;
}
