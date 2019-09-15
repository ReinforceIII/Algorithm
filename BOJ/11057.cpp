/* 11057 오르막 수 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int memo[1001][10];
const int mod = 10007;

int main() {
  int n;
  cin>>n;
  for(int i=0; i<=9; i++) memo[1][i] = 1;
  for(int i=2; i<=n; i++) { //길이
    for(int j=0; j<=9; j++) { //마지막
      memo[i][j] = 0;
      for(int k=0; k<=j; k++) { //그전에 무슨수가 왔나.
        memo[i][j] += memo[i-1][k];
      }
      memo[i][j] %= mod;
    }
  }

  int ans = 0;
  for(int i=0; i<=9; i++) ans += memo[n][i];
  cout<<ans%mod;
  return 0;
}