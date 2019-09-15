/* 16194 카드 구매하기 2 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits.h>

using namespace std;
int price[1001];
int main() {
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++) {
    scanf("%d",&price[i]);
  }
  vector<int> memo(n+1,INT_MAX);
  memo[0] = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      memo[i] = min(memo[i],memo[i-j]+price[j]);
    }
  }
  cout<<memo[n];
  return 0;
}