/* 2529 부등호 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> v, vector<char> e) {
  for(int i=0; i<v.size()-1; i++) {
    if(e[i] == '>') {
      if(v[i] < v[i+1]) return false;
    } else if(e[i] == '<') {
      if(v[i] > v[i+1]) return false;
    }
  }
  return true;
}
//mode :: false = findmax // true = findmin
vector<int> getMaxiMini(vector<int> v1, vector<int> v2,bool mode) {
  string s1,s2;
  for(int i=0; i<v1.size(); i++) {
    s1 += v1[i];
    s2 += v2[i];
  }
  if(mode == false) {
    if(s1.compare(s2) > 0) return v1;
    else return v2;
  } else {
    if(s1.compare(s2) < 0) return v1;
    else return v2;
  }
}
int main() {
  vector<int> numbers = {0,1,2,3,4,5,6,7,8,9};
  int n; cin>>n;
  vector<int> maxi(n+1,0);
  vector<int> mini(n+1,9);
  vector<char> ineq(n);
  for(int i=0; i<n; i++) cin>>ineq[i];

  //1. 최대값 찾기
  vector<int> max_temp = vector<int>(numbers.begin()+(10-n-1),numbers.end());
  do{
    if(check(max_temp,ineq)) maxi = getMaxiMini(maxi,max_temp,false);
  } while(next_permutation(max_temp.begin(),max_temp.end()));
  //2. 최소값 찾기
  vector<int> min_temp = vector<int>(numbers.begin(),numbers.begin() + n+1);
  do{
    if(check(min_temp,ineq)) mini = getMaxiMini(mini,min_temp,true);
  } while(next_permutation(min_temp.begin(),min_temp.end()));

  for(int i : maxi) cout<<i;
  cout<<"\n";
  for(int i : mini) cout<<i;
  return 0;
}