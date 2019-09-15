/* 1912 연속합 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> number(n);
  vector<int> memo(n);
  for(int i=0; i<n; i++) {
    cin>>number[i];
  }
  memo[0] = number[0];
  for(int i=1; i<n; i++) {
    memo[i] = max(memo[i-1]+number[i],number[i]);
  }
  cout<<*max_element(memo.begin(),memo.end());
  return 0;
}