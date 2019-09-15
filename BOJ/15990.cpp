/* 15990 1,2,3 더하기 5 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
long long memo[1000001][4];
const long long mod = 1000000009LL;

int main() {
  for(int i=1; i<=1000000; i++) {
    if(i-1 >= 0) {
      memo[i][1] += memo[i-1][2] + memo[i-1][3];
      if(i == 1) memo[i][1] = 1;
    }
    if(i-2 >= 0) {
      memo[i][2] += memo[i-2][1] + memo[i-2][3];
      if(i == 2) memo[i][2] = 1;
    }
    if(i-3 >= 0) {
      memo[i][3] += memo[i-3][1] + memo[i-3][2];
      if(i == 3) memo[i][3] = 1;
    }
    memo[i][1] %= mod;
    memo[i][2] %= mod;
    memo[i][3] %= mod;
  }
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    cout<<(memo[n][1]+memo[n][2]+memo[n][3])%mod<<"\n";
  }
  return 0;
}