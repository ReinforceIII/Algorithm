/* 2225 합분해 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const long long mod = 1000000000LL;

int main() {
  int n,k;
  cin>>n>>k;
  vector<vector<long long>> memo(k+1,vector<long long>(n+1));
  memo[0][0] = 1LL;
  for(int i=1; i<=k; i++) {
      for(int j=0; j<=n; j++) {
        for(int l=0; l<=j; l++) {
          memo[i][j] += memo[i-1][j-l];
          memo[i][j] %= mod;
        }
      }
  }
  cout<<memo[k][n];
  return 0;
}