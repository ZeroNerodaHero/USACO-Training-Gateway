/*
ID: billyz43
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;
std::ifstream in("fracdec.in");
std::ofstream out("fracdec.out");
map<int,int> used;

int main(){
    int N, D;
    in >> N >> D;
    string str =  to_string(N/D) + '.';
    N = N%D;
    if(N == 0){
        out << str <<"0\n";
        return 0;
    }
    int cur = N;
    int strpos = str.size();
    bool isrep = false;
    for(; cur != 0; strpos++){
//        std::cout << strpos << endl;
//        std::cout << "cur " << cur << "\t\t" << used.find(cur)->second<< endl;
//        std::cout << used.size()<< endl;
  //      std::cout << str << endl;
        if(used.size() > 0 && used.find(cur) != used.end()){
            strpos = used[cur];
            isrep = true;
            break;
        }
        used[cur] = strpos;
        cur *= 10;
        str += char(cur/D)+'0';
        cur %= D;
    }
    if(isrep) str=str.substr(0,strpos)+'('+str.substr(strpos)+')';
    for(int i = 0; i < str.size(); i+= 76){
        out << str.substr(i,76) << endl;
    }
}
