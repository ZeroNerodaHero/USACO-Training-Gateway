/*
ID: billyz43
PROG: twofour
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("twofour.in");
std::ofstream out("twofour.out");
using namespace std;
struct st{
    int n, own[2];
    int arr[30];
    int  adjust(){
        int count = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 2){
                count++;
            } else{
                arr[j++] = arr[i];
            }
        }
        n = j;
        sort(arr,arr+n);
        return count;
    }
    void print(){
        cout << n << ": ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
        cout << "\t|| own " << own[0] << ' ' << own[1] << endl;
    }
};
struct res{
    int own[2];
    res(int a, int b){
        own[0] = a;
        own[1] = b;
    }
};
int N,G;


st dfs(st c, int cp){
cout << cp << "\t";c.print();

    if(c.n == 0){
        cout << "\treturn " << endl;
        return c;
    }
    st nst, best;
    best.own[cp] = -1;
    for(int i = c.n-1; i > 0; i--){
        if(c.arr[i] < 2) break;
        for(int j = 0; j < i; j++){
            if(c.arr[j] > 2) break;
            nst = c;
            nst.arr[i]--;
            nst.arr[j]++;
            nst.own[cp] += nst.adjust();
            nst = dfs(nst,cp^1);
            if(nst.own[cp] > best.own[cp]){
                best = nst;
            }
        }
        if(c.arr[i] == 4){
            if(c.own[(cp^1)] > 0){
                nst = c;
                nst.own[cp^1]--;
                nst.arr[i]--;
                nst.arr[nst.n++] = 3;
                sort(nst.arr,nst.arr+nst.n);
                nst = dfs(nst,cp^1);
                if(nst.own[cp] > best.own[cp]){
                    best = nst;
                }
            }
        }
    }
    return best;
}

int main(){
    in >> N >>G;
    for(int i = 0; i < G; i++){
//cout << "\ncase " << i << endl;  
        st cst;
        cst.n = N;
        int cg = 1;
        for(int i = 0; i < N; i++){
            in >> cst.arr[i];
        }
        int cnt = cst.adjust();
        cst.own[1] = (cnt+1)/2;
        cst.own[0] = (cnt)/2;
        
        st ans = dfs(cst,0);
cout << "result "; ans.print();
        if(ans.own[0] == ans.own[1]){
            out << 0 << endl;
        } else if(ans.own[0] > ans.own[1]){
            out << 1 << endl;
        } else{
            out << 2 << endl;
        }
    }
}
