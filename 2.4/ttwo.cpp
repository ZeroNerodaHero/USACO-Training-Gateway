/*
ID: billyz43
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
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
//        std::cout << minute << endl;
//        std::cout <<"f is:\tx "<< fx << " y "<<fy << endl;
//        std::cout <<"c is:\tx "<< cx << " y "<<cy << endl;
//        std::cout << "------\n\n";
        if(fx == cx && fy == cy){
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
    if(minute == 10000) minute = 0;
    out << minute << endl;
}
