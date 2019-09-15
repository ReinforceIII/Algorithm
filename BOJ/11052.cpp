/* 11052 카드 구매하기 */
#include <iostream>
#include <algorithm>

using namespace std;
int price[1001];
int memo[1001];
int main() {
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++) {
    scanf("%d",&price[i]);
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      memo[i] = max(memo[i],memo[i-j]+price[j]);
    }
  }
  cout<<memo[n];
  return 0;
}