/* 1339 단어수학 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
char m[91];
int main() {
  vector<int> numbers = {0,1,2,3,4,5,6,7,8,9};
  int n; cin>>n;
  cin.ignore();
  vector<char> alpha;
  vector<string> wordlist;
  for(int i=0; i<n; i++) {
    string x;
    getline(cin,x);
    wordlist.push_back(x);
    for(int j=0; j<x.length(); j++) {
      if(find(alpha.begin(),alpha.end(),x[j]) == alpha.end()) alpha.push_back(x[j]);
    }
  }

  sort(alpha.begin(),alpha.end());
  vector<int> us = vector<int>(numbers.begin()+(10-alpha.size()),numbers.end());

  int maxi = 0;
  do {
    int sum = 0;
    for(int i=0; i<us.size(); i++) {
      m[alpha[i]] = us[i];
    }

    for(string s : wordlist) {
      int maxi_temp = 0;
      for(char c : s) {
        maxi_temp = maxi_temp*10 + m[c];
      }
      sum += maxi_temp;
    }
    maxi = max(maxi,sum);
  } while(next_permutation(us.begin(),us.end()));
  cout<<maxi<<endl;
}