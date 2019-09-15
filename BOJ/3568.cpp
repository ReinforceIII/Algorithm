/* 3568 iSharp */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  string s;
  getline(cin,s);
  vector<string> word;
  string now = "";
  for(char c : s) {
    if(c == ' ' || c == ',' || c == ';') {
      if(now.length() > 0) word.push_back(now);
      now = "";
    } else now +=c;
  }
  string base = word[0];
  for(int i=1; i<word.size(); i++) {
    string temp = base;
    string now = word[i];
    while(now.length() > 0 && !('a' <= now.back() && now.back() <= 'z')) {
      if(now.back() == '[') {
        temp += ']';
      } else if(now.back() == ']') {
        temp += '[';
      } else {
        temp += now.back();
      }
      now.pop_back();
    }
    cout<< temp<<' '<<now<<';' <<'\n';
  }
  return 0;
}