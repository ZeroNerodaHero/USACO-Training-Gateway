/*
ID: billy
PROB: pprime
LANG: C++11
*/
#include <iostream>
#include <math.h>
#include <queue>
#include <fstream>
    std::ifstream in("pprime.in");
    std::ofstream out("pprime.out");
using namespace std;
int prime[3] = {5,7,11};
int odd[4] = {1,3,7,9};
int base[4] = {10,100,1000,10000};

typedef pair<int,int> bpair;

bool isprime(int n){
    int y = sqrt(n);
    for(int i = 3; i <= y; i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}

int dcnt(int n){
    int size = 0;
    while(n!=0){
        n/=10;
        size++;
    }
    return size;
}

int pal(int n){
    int a = 0;
    while(n!=0){
        a*=10;
        a+=n%10;
        n/=10;
    }
    return a;
}

void bfs(int a, int b){
    std::queue<bpair> q;
    for(int i = 0; i < 4; i++){
        q.push(bpair(odd[i],3));
    }
    while(!q.empty()){
        bpair n = q.front();
        q.pop();
        int half = pal(n.first);
        int bi = (n.second-1)/2;
        if(n.second&1){
            for(int i = 0; i < 10; i++){
                int num = n.first*base[bi]+i*base[bi-1]+half;
                if(num > b) return;
                //if(num >= a && isprime(num)) out << num << endl;
                q.push(bpair(n.first*10+i,n.second+1));
            }
        } else{
            int num = n.first*base[bi]+half;
            if(num > b) return;
            //if(num >= a && isprime(num)) out << num << endl;
            q.push(bpair(n.first,n.second+1));
        }   
    }
}

int main(){
    int a,b;
    in >> a >> b;
    std::cout << a << ' ' << b << std::endl;
    for(int i = 0; i < 3 && prime[i] <= b; i++){
        if(a > prime[i]) continue;
        out << prime[i] << endl;
    }
    if(b > 100){
        bfs(a,b);
    }
    return 0;
}

