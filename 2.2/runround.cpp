/*
ID: billy
PROG: runround
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool toarray(int num, vector<int> &v){
    vector<bool> cnt(10,false);
    while(num != 0){
        int i = num%10;
        if(!cnt[i]){
            cnt[i] = true;
        } else{
            return false;
        }
        v.insert(v.begin(),i);
        num /= 10;
    }
    return true;;
}

bool check(int num){
    vector<int> v;
    if(!toarray(num,v)){
        return false;
    }
    vector<bool> visit(v.size(),false);
    int i = 0;
    do{
        visit[i] = true;
        i += v[i];
        i %= v.size();
    } while(!visit[i]);
    for(int j = 0; j < v.size(); j++){
        if(!visit[j]) return false;  
    }
    return i == 0;
}

int main(){
    std::ifstream in("runround.in");
    std::ofstream out("runround.out");
    int N;
    in >> N;
    
    for(int i = N+1; ; i++){
        if(check(i)){
            out << i << endl;;
            break;
        }
    }
}


//generate a list
