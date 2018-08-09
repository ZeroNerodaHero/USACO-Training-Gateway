/*
ID: NomNom isHere
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
int main(){
    std::ifstream in("gift1.in");
    std::ofstream out("gift1.out");

    int NP;
    in >> NP;
    std::map<std::string,int> names;
    std::string order[NP];
    for(int i = 0; i < NP; i++){
        std::string name;
        in >> name;
        names[name] = 0;
        order[i] = name;
    }

    for(int i = 0; i < NP; i++){
        std::string person;
        in >> person;
        int amount, number;
        in >> amount >> number;
        if(number == 0) continue;
        names[person] -= amount-amount%number;
        int given = amount/number;

        for(int i = 0; i < number; i++){
            std::string rec;
            in >> rec;
            names[rec] += given;
        }  
    }

    for(int i = 0; i < NP; i++){
        out << order[i] << ' ' << names[order[i]] << '\n';
    }
    return 0;
}
