tring s){
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
    ret*
ID: NomNom
PROG: palsquare
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
    std::ifstream in("palsquare.in");
    std::ofstream out("palsquare.out");
    int base;
    in >> base;

    for(int i = 1; i <= 300; i++){
        int isquare = i * i;
        string digits = convert(isquare,base);
        if(ispal(digits)){
             out << convert(i, base) << ' ' << digits << '\n';;
        }
    }
    return 0;
}
