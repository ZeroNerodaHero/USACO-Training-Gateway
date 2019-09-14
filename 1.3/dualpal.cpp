/*
ID: billyz43
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool ispal(string s){
    int i = 0,j = s.size();
    j--;
    while(i < j && s[i] == s[j]){
        i++; j--;
    }
    return i >= j;
}

string convert(int isquare, int base){
    string nums = "0123456789ABCDEFGHIJ";
    string digits;
    while(isquare != 0){
        digits.insert(digits.begin(),nums[isquare%base]);
        isquare /= base;
    }
    return digits;
}

int main(){
    std::ifstream in("dualpal.in");
    std::ofstream out("dualpal.out");
    int num, start, count = 0;;
    in >> num >> start;

    for(int i = start+1; count < num; i++){
        bool waspal = false;
        for(int b = 10; b > 1; b--){
            if(!waspal) waspal = ispal(convert(i,b));
            else{
                if(ispal(convert(i,b))){
                    out << i << '\n';
                    count++;
                    break;
                }
            }
        }
    }
    return 0;
}
