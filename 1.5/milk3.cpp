/*
ID: NomNom
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;
int cap[3];
vector<int> res;
set<vector<int> > st; 
const int a = 0, b = 1, c = 2;


/*choices:
1.if(C != empty) push to either a or b
if(C empty)
    if(!a) check return;
    if(a) push to either b or c
*/

vector<int> push(vector<int> ar,int n1, int n2){
    ar[n2] += ar[n1];
    int rem = ar[n2] - cap[n2];
    if(rem > 0){
        ar[n2] = cap[n2];
        ar[n1] = rem;
    } else{
        ar[n1] = 0;
    }
    return ar;
}

void action(vector<int> ar){
    std::cout << ar[a] << ' ' << ar[b] << ' ' << ar[c] << std::endl;
    if(st.find(ar) != st.end()) return;
    st.insert(ar);
    if(ar[a] == 0) res.push_back(ar[c]);
    for(int i = 0; i < 3; i++){
        if(ar[i] != 0){
            action(push(ar,i,(i+1)%3));
            action(push(ar,i,(i+2)%3));
        }
    } 
}

void print(std::vector<int> ar, int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

int main(){
    std::ifstream in("milk3.in");
    std::ofstream out("milk3.out");

    in >> cap[0] >> cap[1] >> cap[2];
    vector<int> ar(3);
    ar[2] = cap[2];
    action(ar);
    sort(res.begin(),res.end());
    for(int i = 0; i < res.size()-1; i++){
        out << res[i] << ' ';
    } out << res[res.size()-1] << std::endl;
    return 0;   
}
