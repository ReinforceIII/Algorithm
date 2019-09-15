#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

bool check(string s) {
  string molist="aeiou";
  int mo=0;
  int ja=0;
  for(char c : s) {
    if(molist.find(c) != string::npos) mo++;
    else ja++;
  }
  return ja >=2 && mo >= 1;
}

//len = 암호 길이, alpha = alphabet , password = 만들고있는 패스워드 , index = 넣을 지 말지 결정해야할 인덱스
void recur(int len, vector<char> alpha, string password, int index) {
  if(password.length() == len) {
    if(check(password)) {
      cout<<password<<"\n";
    }
    return;
  }
  if(index >= alpha.size()) return;
  recur(len,alpha,password+alpha[index],index+1);
  recur(len,alpha,password,index+1);
}

int main() {
  int l,c;
  cin>>l>>c;
  vector<char> alpha;
  for(int i=0; i<c; i++) {
    char c;
    cin>>c;
    alpha.push_back(c);
  }
  sort(alpha.begin(),alpha.end());

  recur(l,alpha,"",0);
  return 0;
}