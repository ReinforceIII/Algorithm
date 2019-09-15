/* 11053 가장 긴 증가하는 부분 수열 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> map(n);
  vector<int> memo(n,1);
  for(int i=0; i<n; i++) {
    cin>>map[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(map[i] > map[j] && memo[i] < memo[j]+1) {
        memo[i] = memo[j] + 1;
      }
    }
  }
  cout<<*max_element(memo.begin(),memo.end());
  return 0;
}