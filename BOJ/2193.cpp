/* 2193 이친수 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
long long memo[91][2];

int main() {
  memo[1][0] = 0;
  memo[1][1] = 1;
  int n;
  cin>>n;
  for(int i=2; i<=n; i++) { //길이
    memo[i][0] = memo[i-1][0] + memo[i-1][1];
    memo[i][1] = memo[i-1][0];
  }
  long long ans = memo[n][0]+memo[n][1];
  cout<<ans;
  return 0;
}