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

        string key[] = {"CBA","FED","IHG","LKJ","ONM","SPR","VUT","YXW"};
        string &s = key[number[n.loc] - '2'];
        
        for(int l = 0; l < s.size(); l++){
            st.push(name(s[l],n.loc+1,n.low,n.high));
        }
    }

    if(nsol) out << "NONE\n";
    return 0;
}
