/*
ID: billyz43
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;
std::ifstream in("ttwo.in");
std::ofstream out("ttwo.out");
char farm[10][10];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct sq{
    int fx,fy,fdir,cx,cy,cdir;
    sq(int fx,int fy,int fdir,int cx,int cy,int cdir):
        fx(fx),fy(fy),fdir(fdir),cx(cx),cy(cy),cdir(cdir) {}
};
//unordered_map<int,int> s;
unordered_set<int> s = {};
bool found(int fx, int fy, int fdir, int cx, int cy, int cdir){
    int state =((fx<<24)|(fy<<20)|(fdir<<16)|(cx<<8)|(cy<<4)|cdir);
    if(s.find(state)== s.end()){
        s.insert(state);
        return false;
    }
    return true;
}

#if 0
bool found(int fx, int fy, int fdir, int cx, int cy, int cdir){
    int state =((fx<<24)|(fy<<20)|(fdir<<16)|(cx<<8)|(cy<<4)|cdir);
    if(s.find(state)!= s.end()){
        s.insert(state);
        return false;
    }
    return true;
}
bool found(int fx, int fy, int fdir, int cx, int cy, int cdir){
    int state =((fx<<24)|(fy<<20)|(fdir<<16)|(cx<<8)|(cy<<4)|cdir);
    if(s[state]==0){
        s[state] = 1;
        return false;
    }
    return true;
}
#endif
int main(){
    int fx,fy,fdir = 0;
    int cx,cy, cdir = 0;;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            in >> farm[i][j];
            if(farm[i][j] == 'F'){
                fx = i;
                fy = j;
            }   
            if(farm[i][j] == 'C'){
                cx = i;
                cy = j;
            }
        }   
    }
    int minute = 0;
    for(; minute < 10000; minute++){
        if(fx == cx && fy == cy){
            break;           
        }
        if(found(fx,fy,fdir,cx,cy,cdir)){
            cout << minute << endl;
            minute = 0;
            break;
        }
        int nfx = fx+dx[fdir], nfy = fy+dy[fdir];
        int ncx = cx+dx[cdir], ncy = cy+dy[cdir];
    
        if(nfx < 0 || nfx >= 10 ||
           nfy < 0 || nfy >= 10 ||
           farm[nfx][nfy] == '*'){
            fdir = (fdir+1)%4;
        } else{
            fx = nfx;
            fy = nfy; 
        }
        if(ncx < 0 || ncx >= 10 ||
           ncy < 0 || ncy >= 10 ||
           farm[ncx][ncy] == '*'){
            cdir = (cdir+1)%4;
        } else{
            cx = ncx;
            cy = ncy;
        }
        
    }
    out << minute << endl;
}
