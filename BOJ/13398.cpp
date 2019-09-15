/* 13398 연속합 2 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> number(n);
  vector<int> memo_left(n);
  vector<int> memo_right(n);
  for(int i=0; i<n; i++) {
    cin>>number[i];
  }
  memo_left[0] = number[0];
  for(int i=1; i<n; i++) {
    memo_left[i] = max(memo_left[i-1]+number[i],number[i]);
  }
  memo_right[n-1] = number[n-1];
  for(int i=n-2; i>=0; i--) {
    memo_right[i] = max(memo_right[i+1]+number[i],number[i]);
  }
  int result = *max_element(memo_left.begin(),memo_left.end());
  for(int i=1; i<n-1; i++) {
    result = max(result,memo_left[i-1]+memo_right[i+1]);
  }
  cout<<result;
  return 0;
}