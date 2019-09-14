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
    vector<int> digits;
    cout << N/D << '.';
    cout  << endl; 
    N = N%D;
    while(N != 0){
        digits.push_back(N%10);
        N /= 10; 
    }
    for(int i = 0; i < digits.size(); i++){
        std::cout << digits[i] << ' ';
    }
    int cur = 0;
    int strpos = 0;
    string str = "";
    bool isrep = false;
    for(int i = digits.size()-1; true; i--){
        std::cout << str << endl;
        if(used.find(cur) != used.end()){
            strpos = used[cur];
            isrep = true;
            break;
        }
        cur *= 10;
        if(i >= 0) cur += digits[i]; 
        std::cout  << cur << endl;
        if(cur/D > 0){
            str += char(cur/D)+'0';
            strpos++;
            used[cur] = strpos;
            cur %= D;
        } else{
            str += '0';
        }
    }
    if(isrep) cout << str.substr(0,strpos) << '(' << str.substr(strpos) << ')' << endl;
    else cout << str << endl;
}
