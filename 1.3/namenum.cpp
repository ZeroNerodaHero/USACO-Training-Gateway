/*
ID: billyz43
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
        std::string name;
        fin >> name;
        if(name.size() == len && !fin.fail()){
            int j = 0;
            while(j < len && letter[name[j]] == number[j]) j++;
            if(j == len){
                out << name << '\n';
                isempty = false;
            }                 
        }
    }
    if(isempty) out << "NONE" << '\n';   
    return 0;
}
