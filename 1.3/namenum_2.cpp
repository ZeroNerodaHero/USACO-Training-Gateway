/*
ID: NomNom
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;
string dict[5000];

struct name{
    int loc, low, high;
    char ch;
    name(char ch,int loc, int low, int high): ch(ch), loc(loc), low(low), high(high) {}
    
};
int main(){
    std::ifstream in("namenum.in");
    std::ifstream fin("dict.txt");
    std::ofstream out("namenum.out");

    std::string number;
    in >> number;
    int lens = number.size();
    bool nsol = true;
   
    string sol;
    sol.resize(lens);
    int i = 0;
    while(!fin.eof()){
        fin >> dict[i];
        //cout << "s: " << dict[i] << endl;
        if(dict[i].size() == lens){
            //cout  << i << '\t'<< dict[i] << endl;
            i++;
        }
    }
    stack<name> st;
    st.push(name(0,0,0,i));
    while(!st.empty()){
        name n = st.top();
        st.pop();
        if(n.loc == lens){
            sol[n.loc-1] = n.ch;
            for(int k = n.low; k < n.high; k++){
                if(sol == dict[k]){
                    nsol = false;
                    out << sol << '\n';
                    break;
                }
            }    
            continue;
        } 
        else if(n.loc > 0){
            int j;
            bool nfound = true;
            for(j = n.low; j < n.high; j++){
                if(n.ch == dict[j][n.loc-1]){
                    n.low = j;
                    while(n.ch  ==  dict[j][n.loc-1]) j++;
                    n.high = j;
                    nfound =false;
                    break;
                }
            }    
            if(nfound) continue;       
            sol[n.loc-1] = n.ch;
        }

        switch(number[n.loc]){
      case '2':st.push(name('C',n.loc+1,n.low,n.high));
               st.push(name('B',n.loc+1,n.low,n.high));
               st.push(name('A',n.loc+1,n.low,n.high));
               break; 
      case '3':st.push(name('F',n.loc+1,n.low,n.high));
               st.push(name('E',n.loc+1,n.low,n.high));
               st.push(name('D',n.loc+1,n.low,n.high));
               break; 
      case '4':st.push(name('I',n.loc+1,n.low,n.high));
               st.push(name('H',n.loc+1,n.low,n.high));
               st.push(name('G',n.loc+1,n.low,n.high));
               break; 
      case '5':st.push(name('L',n.loc+1,n.low,n.high));
               st.push(name('K',n.loc+1,n.low,n.high));
               st.push(name('J',n.loc+1,n.low,n.high));
               break; 
      case '6':st.push(name('O',n.loc+1,n.low,n.high));
               st.push(name('N',n.loc+1,n.low,n.high));
               st.push(name('M',n.loc+1,n.low,n.high));
               break; 
      case '7':st.push(name('S',n.loc+1,n.low,n.high));
               st.push(name('P',n.loc+1,n.low,n.high));
               st.push(name('R',n.loc+1,n.low,n.high));
               break; 
      case '8':st.push(name('V',n.loc+1,n.low,n.high));
               st.push(name('U',n.loc+1,n.low,n.high));
               st.push(name('T',n.loc+1,n.low,n.high));
               break; 
      case '9':st.push(name('Y',n.loc+1,n.low,n.high));
               st.push(name('X',n.loc+1,n.low,n.high));
               st.push(name('W',n.loc+1,n.low,n.high));
               break;
   }
    }

    if(nsol) out << "NONE\n";
    return 0;
}
