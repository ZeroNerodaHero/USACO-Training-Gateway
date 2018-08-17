/*
ID: NomNom
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("namenum.in");
    std::ifstream fin("dict.txt");
    std::ofstream out("namenum.out");

    std::map<char,char> letter;
    char a = 'A';
    for(char i = 50; i < 57; i++){
        for(int j = 0; j < 3; j++,a++){
            if(a == 'Q'){
                a++;
            }
            letter[a] = i;
        }
    }

    std::string number;
    in >> number;
    int len = number.size();
   
    bool isempty = true;;
     
    while(!fin.eof()){
    //for(int i = 0; i < 4617; i++){
        std::string name;
        fin >> name;
        if(name.size() == len && !fin.fail()){
            for(int j = 0; j < len; j++){
                if(letter[name[j]] != number[j])
                    break;
                if(j == len-1){
                    out << name << '\n';
                    isempty = false;
                }                 
            }
        }
    }
    if(isempty) out << "NONE" << '\n';   
    return 0;
}
