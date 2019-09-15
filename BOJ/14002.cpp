/* 14002 가장 긴 증가하는 부분 수열 4*/
#include <iostream>
#include <algorithm>
#include <vector>

int map[1000];
int memo[1000];
int before[1000];

using namespace std;

void recur(int x) {
  if(x == -1) return;
  recur(before[x]);
  cout<<map[x]<<" ";
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>map[i];
  }
  for(int i=0; i<n; i++) {
    memo[i] = 1;
    before[i] = -1;
    for(int j=0; j<i; j++) {
      if(map[i] > map[j] && memo[i] < memo[j]+1) {
        memo[i] = memo[j] + 1;
        before[i] = j;
      }
    }
  }
  int result = memo[0];
  int r_index = 0;
  for(int i=1; i<n; i++) {
    if(result < memo[i]) {
      result = memo[i];
      r_index = i;
    }
  }
  cout<<result<<"\n";
  recur(r_index);
  return 0;
}