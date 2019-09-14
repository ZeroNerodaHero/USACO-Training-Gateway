/*
ID: billyz43
PROB: pprime
LANG: C++11
*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <vector>
    std::ifstream in("pprime.in");
    std::ofstream out("pprime.out");
using namespace std;
int prime[3] = {5,7,11};
int odd[4] = {1,3,7,9};
//int ar[10000];
vector<int> ar;
int size = 0;
int a,b;

bool isprime(int n){
    int y = sqrt(n);
    for(int i = 3; i <= y; i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}

inline int pal(int buf[],int l, int even){
    int j = l+1;
    for(int i = even?l:l-1; i >= 0; i--){
        buf[j++] = buf[i];
    } 
    int sum = 0;
    for(int i = 0; i < j; i++){
        sum = sum*10+buf[i];
    }
    return sum;
}

void dfs(int buf[], int l){
    for(int i = 0; i < 10; i++){
        buf[l] = i;
        for(int j = 0; j < 2; j++){
            int n = pal(buf,l,j);
            if(n > b){
                if(j) continue;
                else return;
            }
            if(n < a) continue;
            //if(isprime(n)) ar[size++] = n;
            if(isprime(n)) ar.push_back(n);
        }
        dfs(buf,l+1);
    }
}

int main(){
    in >> a >> b;
    std::cout << a << ' ' << b << std::endl;
    for(int i = 0; i < 3 && prime[i] <= b; i++){
        if(a > prime[i]) continue;
        out << prime[i] << endl;
    }
    int buf[16];
    if(b > 100){
        for(int i = 0; i < 4; i++){
            buf[0] = odd[i];
            dfs(buf,1);
        }
    }
    //sort(ar,ar+size);
    sort(ar.begin(),ar.end());
    //for(int i = 0; i < size; i++){
    for(int i = 0; i < ar.size(); i++){
        out << ar[i] << endl; 
    }
    return 0;
}

