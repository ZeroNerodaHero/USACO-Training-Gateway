/*
ID: billy
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int V, G;
vector<int> v(100,100);
int need[25];
int vit[15][25];

void print(vector<int> &vi){
    std::cout << "v is ";
    for(int i = 0; i < vi.size(); i++){
        std::cout << vi[i] << ' ';
    } std::cout << endl;
}

bool check(vector<int> &q){
    if(!q.size()) return false;
    for(int j = 0; j < V; j++){
        int total = 0;
        for(int i = 0; i < q.size(); i++){
            //std::cout << vit[q[i]][j] << "\t";
            total+=vit[q[i]][j];        
        }
        //std::cout << j <<" - " <<total << endl;
        if(total < need[j]) return false;
    }
    return true;
}

void gen(vector<int> &ar,int pos){
    //print(ar);
    //std::cout << check(ar) << endl;
    if(check(ar)){
        //std::cout << "was true\n--------";
        if(ar.size() < v.size()){
            //std::cout << "works\n";
            v = ar;
        }
        return;
    }
    if(pos == G || ar.size() >= v.size()) return;
    ar.push_back(pos);
    gen(ar,pos+1);
    ar.pop_back(); 
    gen(ar,pos+1);
}

int main(){
    std::ifstream in("holstein.in");
    std::ofstream out("holstein.out");
    
    in >> V;
    for(int i = 0; i < V; i++){
        in >> need[i];
    }
    in >> G;
    for(int i = 0; i < G; i++){
        for(int j = 0; j < V; j++){
            in >> vit[i][j];
        }
    } 

    //for(int i = 0; i < V; i < G

    vector<int> q;
    gen(q,0);
    std::cout << "anser is "; print(v);
    out << v.size() << ' ';
    for(int i = 0; i < v.size()-1; i++){
        out << v[i]+1 << ' ';
    } out << v[v.size()-1]+1 << endl;
}

