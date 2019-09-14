/*
ID: billyz43
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
bool nums[10];
int ar[10];
int N;

bool isvalid(int a){
    while(nums[a%10]){
        a /= 10;
    }
    return a == 0;
}

int multiply(int a){
    int count = 0;
    int ans[N];
    int i = 0;
    for(int l = 0; l < N; l++){
        int b = a * ar[l];
        if(b < 1000 && isvalid(b)) ans[i++] = b;
    }
    for(int j = 0; j < i; j++){
        for(int k = 0; k < i; k++){
            if(isvalid(ans[j]*10 + ans[k])) count++;
        }
    }
    return count;
}

int main(){
    std::ifstream in("crypt1.in");
    std::ofstream out("crypt1.out");

    //int N;
    in >> N;
    for(int i = 0; i < N; i++){
        in >> ar[i];
        nums[ar[i]] = true;
    }
    int count = 0;

    for(int i = 0; i < N; i++){
        int ni = ar[i];
        for(int j = 0; j < N; j++){
            int nj = ni*10+ar[j];
            for(int k = 0; k < N; k++){
                int nk = nj*10+ar[k];
                count += multiply(nk);
            }
        }
    }
    out << count << std::endl;
    return 0;
}

