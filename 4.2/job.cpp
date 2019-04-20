/*
ID: billy
PROG: job
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
std::ifstream in("job.in");
std::ofstream out("job.out");

int N,M1,M2;
multimap<int,int> m1;
multimap<int,int> m2;

void print(multimap<int,int>& m){
    cout << "times\n";
    for(auto& i: m){
        cout << i.first << ' ' << i.second << endl;
    }
}

void solve(multimap<int,int> &m,int M){
    int ar[30];
    for(int  i = 0; i < M; i++){
        in >> ar[i];
     //   cout << ar[i] << endl;
        m.insert(pair<int,int>(ar[i],i));
    }
    for(int i = M; i < N+M; i++){
        auto it = next(m.begin(),i-M);
      //  cout << it->first << ' ' << it->second << endl;
        m.insert(pair<int,int>(it->first+ar[it->second],it->second));
    } 
 //   print(m);
}

int main(){
    in >> N >> M1 >> M2;

    solve(m1,M1);
    //cout << "m2" <<endl;
    solve(m2,M2);

    int small = 0;
    auto i2 = m2.begin();
    for(auto i1 = next(m1.rbegin(),M1); i1 != m1.rend();i1++,i2++){
//        cout << i1->first << ' ' << i2->first << endl;
        small = max(small,i1->first+i2->first);
    }    
    out << next(m1.rbegin(),M1)->first << ' ' << small << endl;
}
