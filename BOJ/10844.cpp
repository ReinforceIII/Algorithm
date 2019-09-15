/* 10844 쉬운 계단 수 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
long long memo[101][10];
const long long mod = 1000000000LL;

int main() {
  int n;
  cin>>n;
  for(int i=1; i<=9; i++) memo[1][i] = 1;
  for(int i=2; i<=n; i++) {
    for(int j=0; j<=9; j++) {
      memo[i][j] = 0;
      if(j-1 >= 0) memo[i][j] += memo[i-1][j-1];
      if(j+1 <= 9) memo[i][j] += memo[i-1][j+1];

      memo[i][j] %= mod;
    }
  }

  long long ans = 0;
  for(int i=0; i<=9; i++) ans += memo[n][i];
  cout<<ans%mod;
  return 0;
}