/* 1699 제곱수의 합 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> number(n+1);
  vector<int> memo(n+1);
  for(int i=1; i<=n; i++) {
      memo[i] = i;
      for(int j=1; j*j<=i; j++) {
        if(memo[i] > memo[i-j*j] + 1) memo[i] = memo[i-j*j] + 1;
      }
  }
  cout<<memo[n];
  return 0;
}