/* 11055 가장 큰 증가 부분 수열 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> map(n);
  vector<int> memo(n);
  for(int i=0; i<n; i++) {
    int temp;
    cin>>temp;
    map[i] = temp;
    memo[i] = temp;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(map[i] > map[j] && memo[i] < memo[j]+map[i]) {
        memo[i] = memo[j] + map[i];
      }
    }
  }
  cout<<*max_element(memo.begin(),memo.end());
  return 0;
}