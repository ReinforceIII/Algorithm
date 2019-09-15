/* 9465 스티커 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int map[100001][2];
long long memo[100001][3];

int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%d",&map[i][0]);
    for(int i=1; i<=n; i++) scanf("%d",&map[i][1]);
    memo[0][0] = 0; memo[0][1] = 0; memo[0][2] = 0;
    for(int i=1; i<=n; i++) {
      memo[i][0] = max(memo[i-1][0],max(memo[i-1][1],memo[i-1][2]));
      memo[i][1] = max(memo[i-1][0],memo[i-1][2]) + map[i][0];
      memo[i][2] = max(memo[i-1][0],memo[i-1][1]) + map[i][1];
    }
    long long ans = max(memo[n][0],max(memo[n][1],memo[n][2]));
    cout<<ans<<"\n";
  }
  return 0;
}