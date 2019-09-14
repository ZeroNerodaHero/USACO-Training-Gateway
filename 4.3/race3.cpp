/*
ID: billyz43
PROG: race3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <list>
#include <cstring>
using namespace std;
std::ifstream in("race3.in");
std::ofstream out("race3.out");

list<int> course[50];
int N = 0;

void print(){
    for(int i = 0; i < N; i++){
        cout << i << '\t';
        for(auto& j: course[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
}

bool bfs1(int s,bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        
        for(auto& i: course[t]){
            if(i < s) return false;
            if(visited[i]) continue;
            q.push(i);
            visited[i] = true;
        }
    }
    
    return true;
}

bool bfs(bool visited[]){
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        
        for(auto& i: course[t]){
            if(visited[i]) continue;
            q.push(i);
            visited[i] = true;
        }
    }
    
    return !(visited[N-1]);
}

void find(){
    vector<int> unavoid,split;
    for(int i = 1; i < N-1; i++){
        bool visited[N];
        memset(visited,0,sizeof(visited));
        visited[i] = true;
        if(bfs(visited)){
            unavoid.push_back(i);
        }
    }
    out << unavoid.size() ;
    for(auto& i: unavoid) out << ' ' <<  i;
    out << endl;

    for(auto& i: unavoid){
        bool visited[N];
        memset(visited,0,sizeof(visited));
        visited[i] = true;
        if(bfs1(i,visited)){
            split.push_back(i);
        }
    }   
    out << split.size();
    for(auto& i: split) out << ' ' << i;
    out << endl;
}

int main(){
    for(; true; N++){
        int con;
        do{
            in >> con;
            if(con == -2) break;
            if(con == -1) break;
            course[N].push_back(con);
        } while(1);
        if(con == -1) break;
    }
//    print();
    find();    
}
