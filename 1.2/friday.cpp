/*
ID: NomNom isHere
PROG: friday
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

void print(int ar[]){
    for(int i = 0; i < 7; i++){
       cout << ar[i] << ' ';
    } cout << '\n';
}

int main(){
    std::ifstream in("friday.in");
    std::ofstream out("friday.out");

    int year;
    in >> year;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days[7];
    //memset(days,0,7);
    for(int i = 0; i < 7; i++){
        days[i] = 0;
    }    


    int prev = 2; 
    for(int i = 0; i < year; i++){
        bool leap = ((1900+i)%4 == 0) && !((1900+i)%100 == 0);
        if(!leap) leap = ((1900+i)%400 == 0);
        std:cout << 1900+i << " leap: " << leap << std::endl;
        for(int j = 0; j < 12; j++){
            std::cout << prev << '\t';
            std::cout << "13: " << (prev+12)%7 << '\t';;
            days[(prev+12)%7]++;
            if(leap && j == 1)
                prev = (prev+29)%7;
            else
                std::cout << prev+month[j] << '\t';
                prev = (prev+month[j])%7;
            print(days);
        }
    }
    for(int i = 0; i < 6; i++){
        out << days[i] << ' ';
    } out << days[6] << '\n';
}
