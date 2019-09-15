/* 15988 1,2,3 더하기 3 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
long long memo[1000001];
const long long mod = 1000000009LL;

int main() {
  memo[0] = 1;
  for(int i=1; i<=1000000; i++) {
    if(i-1 >= 0) memo[i] += memo[i-1];
    if(i-2 >= 0) memo[i] += memo[i-2];
    if(i-3 >= 0) memo[i] += memo[i-3];
    memo[i] %= mod;
  }
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    cout<<memo[n]<<"\n";
  }
  return 0;
}