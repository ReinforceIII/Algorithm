/* 2156 포도주 시식 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d",&n);
  vector<int> wine(n+1,0);
  vector<long long>memo(n+1,0);
  for(int i=1; i<=n; i++) {
    scanf("%d",&wine[i]);
  }
  memo[1] = wine[1];
  memo[2] = wine[1]+wine[2];
  for(int i=3; i<=n; i++) {
    memo[i] = max(memo[i-1],max(memo[i-2]+wine[i],memo[i-3]+wine[i-1]+wine[i]));
  }
  cout<<memo[n];
  return 0;
}