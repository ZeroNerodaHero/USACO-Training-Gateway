// skipws flag example
#include <iostream>     // std::cout, std::skipws, std::noskipws
#include <sstream>      // std::istringstream
#include <string>
using namespace std;

int main () {
  char a, b, c;
  string s;
  std::istringstream iss ("  123");

iss >> noskipws >> s;
    cout << "[" << s << ']' << endl;
  iss.seekg(0);
  iss >> std::noskipws >> a >> b >> c;
  std::cout << a << b << c << '\n';
  return 0;
}
