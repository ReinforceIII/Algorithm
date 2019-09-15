/* 11726 2xn 타일링 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int memo[10001];

int main() {
  int n;
  cin>>n;
  memo[0] = 1;
  memo[1] = 1;
  for(int i=2; i<=n; i++) {
    memo[i] = memo[i-1] + memo[i-2];
    memo[i]%=10007;
  }
  cout<<memo[n];
  return 0;
}