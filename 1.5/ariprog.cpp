/*
ID: billyz43
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <fstream>
using namespace std;

struct ap{
    int end, diff;
    ap(int end, int diff): end(end),diff(diff) {}
    bool operator <(const ap &o) const{
        return diff > o.diff || (diff == o.diff && end > o.end); 
    }
};

bool isthere(int key, unordered_set<int> &st){
    return st.find(key)!=st.end();
}

int main(){
    std::ifstream in("ariprog.in");
    std::ofstream out("ariprog.out");
    int N, M,size;
    in >> N >> M;
    priority_queue<ap> q;
    int seq[M+1];
    unordered_set<int> s;
    vector<int> v;
    for(int i = 0; i <= M; i++){
        seq[i] = i*i;
    }

    for(int i = 0; i <= M; i++){
        for(int j = i; j <= M; j++){
            s.insert(seq[i] + seq[j]);
        }
    }
    v.insert(v.begin(),s.begin(),s.end());
    sort(v.begin(),v.end());

    for(int i = 0; i < v.size()-N+1; i++){
        for(int j = i+1; j < v.size()-N+2; j++){
            int count = 2,diff = v[j]-v[i],tmp=v[j]+diff;
            if(v[i]+(N-1)*diff > 2*M*M) continue;
            while(count < N){
                if(!isthere(tmp,s)) break;
                tmp += diff;
                count++;
            }
            if(count == N){
                q.push(ap(v[i],diff));
            }
        }    
    }

    if(q.empty()){
        out << "NONE" << endl;
    }
    while(!q.empty()){
        ap i = q.top();
        q.pop();
        out << i.end << ' ' <<i.diff << endl;
    }

    return 0;   
}
