/* 11054 가장 긴 바이토닉 부분 수열 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> map(n);
  vector<int> memo_up(n,1);
  vector<int> memo_down(n,1);
  for(int i=0; i<n; i++) {
    cin>>map[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(map[i] > map[j] && memo_up[i] < memo_up[j]+1) {
        memo_up[i] = memo_up[j] + 1;
      }
    }
  }
  for(int i=n-1; i>=0; i--) {
    for(int j=i+1; j<n; j++) {
      if(map[i] > map[j] && memo_down[i] < memo_down[j]+1) {
        memo_down[i] = memo_down[j] + 1;
      }
    }
  }
  int result = 0;
  for(int i=0; i<n; i++) {
    result = max(result,memo_up[i]+memo_down[i]-1);
  }
  cout<<result;
  return 0;
}