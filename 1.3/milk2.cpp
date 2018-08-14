/*
ID: NomNom
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("milk2.in");
    std::ofstream out("milk2.out");

    int N;
    in >> N;
    
    std::cout << "N:\t" <<  N << '\n';
    map<int,int> seconds;    

    int milkstart, milkend;
    int idlelong, milklong;
    for(int i = 0; i < N; i++){
        int a,b;
        in >> a >> b;
        seconds[a] = max(b, seconds[a]);
    }

    std::cout << seconds.size() << '\n';

    std::map<int,int>::iterator it=seconds.begin();
    milkstart = it->first;
    milkend = it->second;
    milklong = milkend - milkstart;
    idlelong = 0;
    it++;

    for(; it!=seconds.end(); ++it){
        int a = it->first, b = it->second;
        if(a <= milkend){
            milkend = max(b,milkend);
            milklong = max(milkend - milkstart,milklong);
        }
        else{
            std::cout << "Changed:";
            std::cout << a<<'-' << b <<'\n'<< milkstart << '-'<< milkend << std::endl;
            idlelong = max(a-milkend, idlelong);
            milkstart = a;
            milkend = b;       
            milklong = max(milkend - milkstart,milklong);
        }
    }
    std::cout << milklong << ' ' << idlelong << endl;
    out << milklong << ' ' << idlelong << endl;
}
