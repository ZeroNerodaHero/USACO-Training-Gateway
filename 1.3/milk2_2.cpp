/*
ID: NomNom
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct interval{
    int s, e;
    interval(int s=0, int e=0): s(s), e(e){};
    bool operator < (const interval &o) const{
        return s < o.s;
    }
};

interval v[5000];

int main(){
    ifstream in("milk2.in");
    ofstream out("milk2.out");

    //long long m = 100000000;
    int m = 100000000;
    m *= m;
    cout << m << endl;

    int N;
    in >> N;
 
    cout << "N:\t" <<  N << '\n';
    //vector<interval> v(N);

    for(int i = 0; i < N; i++){
        in >> v[i].s >> v[i].e;
    }

    //sort(v.data(),v.data()+N);
    //sort(v.begin(),v.end());
    sort(v,v+N);

    int s, e,il, ml;
    s = v[0].s;
    e = v[0].e;
    ml = e - s;
    il = 0;
    
    for(int i = 1; i < N; ++i){
        int a = v[i].s, b = v[i].e;
        if(a <= e){
            e = max(b, e);
            ml = max(e - s, ml);
        }
        else{
            cout << "Changed:";
            cout << a<<'-' << b <<'\n'<< s << '-'<< e << endl;
            il = max(a-e, il);
            s = a;
            e = b;       
            ml = max(e - s,ml);
        }
    }
    cout << ml << ' ' << il << endl;
    out << ml << ' ' << il << endl;
}
