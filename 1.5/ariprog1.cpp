/*
ID: billyz43
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <queue>
#include <set>
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

bool isthere(int key, vector<int> &v, int l, int &r){
    while(l <= r){
        int mid = (l+r)/2;
        if(v[mid] == key){
             r = mid-1;
             return true;
        }
        if(v[mid] > key) r = mid-1;
        else l = mid + 1;
    }
    return false;
}

int main(){
    std::ifstream in("ariprog.in");
    std::ofstream out("ariprog.out");
    int N, M,size;
    in >> N >> M;
    priority_queue<ap> q;
    int seq[M+1];
    set<int> s;
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
    set<int*> st;

#if 1
    for(int i = 0; i <= v.size()-N; i++){
        for(int j = i+1; j < v.size()-N+2; j++){
            int count = 2,diff = v[j]-v[i],tmp=v[j]+(N-2)*diff;;
            if(tmp > v[v.size()-1]) continue;
            int r = v.size()-1;
            while(count != N){
                if(!isthere(tmp,v,j+1,r)){
                    break;
                }
                tmp-=diff;
                count++;
            }           
            if(count == N){
                q.push(ap(v[i],diff));
                
            }
        }
    }
#endif

#if 0
    for(int i = 0; i <= v.size()-N; i++){
        for(int j = i+1; j < v.size()-N+2; j++){
            int count = 2,diff = v[j]-v[i],tmp=v[j]+(N-2)*diff;;
            if(tmp > v[v.size()-1]) continue;
            int r = v.size()-1;
            while(count != N){
                if(!isthere(tmp,v,j+1,r)){
                    break;
                }
                tmp-=diff;
                count++;
            }           
            if(count == N){
                q.push(ap(v[i],diff));
            }
        }
    }
#endif
#if 0
    for(int i = 0; i < v.size()-N; i++){
        for(int j = i+1; j < v.size(); j++){
            int count = 2,diff = v[j]-v[i],tmp=v[j]+diff;
            for(int k = j+1;k < v.size() && v[k] <= tmp; k++){
                if( v[k] == tmp){
                    tmp = v[k]+diff;
                    count++;
                    if(count == N){
                        q.push(ap(v[i],diff));
                        break;
                    }
                }
            }
        }    
    }
#endif
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
