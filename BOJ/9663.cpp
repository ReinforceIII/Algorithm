/* 9663 N-Queen */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int n;
int queen[15];
int result = 0;
using namespace std;

bool check(int c) {
  for(int i = 1; i<c; i++) {
    if(queen[i] == queen[c]) return false;
    if(abs(queen[i] - queen[c]) == abs(i-c)) return false;
  }
  return true;
}

void dfs(int index) {
  if(index == n) {
    ++result;
    return;
  }
  for(int i=1; i<=n; i++) {
    queen[index+1] = i;
    if(check(index+1)) dfs(index+1);
    else queen[index+1] = 0;
  }

  queen[index] = 0;
}

int main() {
  cin>>n;
  for(int i=1; i<=n; i++) {
    queen[1] = i;
    dfs(1);
  }
  cout<<result;
  return 0;
}