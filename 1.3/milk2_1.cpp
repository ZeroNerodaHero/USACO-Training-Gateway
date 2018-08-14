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
    multimap<int,int> seconds;    

    int milkstart, milkend;
    int idlelong, milklong;
    for(int i = 0; i < N; i++){
        int a,b;
        in >> a >> b;
        seconds.insert(pair<int,int>(a,b));
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
        }
        else{
            std::cout << "Changed:";
            std::cout << a<<'-' << b <<'\n'<< milkstart << '-'<< milkend << std::endl;
            milklong = max(milkend - milkstart,milklong);
            idlelong = max(a-milkend, idlelong);
            milkstart = a;
            milkend = b;       
        }
    }
    milklong = max(milkend - milkstart,milklong);
    
    std::cout << milklong << ' ' << idlelong << endl;
    out << milklong << ' ' << idlelong << endl;
}
