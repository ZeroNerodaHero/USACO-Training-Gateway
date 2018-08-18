/*
ID: NomNom
PROG: milk
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("milk.in");
    std::ofstream out("milk.out");
    int N, M, cost = 0;
    in >> N >> M;
    std::map<int,int> milk;
    for(int i = 0; i < M; i++){
        int P, A;
        in >> P >> A;
        milk[P] += A;
    }
 
    for(map<int,int>::iterator i = milk.begin(); i != milk.end(); i++){
        if(N > i->second){
            N -= i->second;
            cost += i->first * i->second;
        } else{
            cost += i->first * N;
            break; 
        }
    }    
    out << cost << endl;
    return 0;   
}
