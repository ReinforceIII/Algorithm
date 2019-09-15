/* 1890 점프 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 100
int game[MAX_SIZE][MAX_SIZE];
long long resolve[MAX_SIZE][MAX_SIZE];
using namespace std;
int main() {
  int n; cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>game[i][j];
    }
  }

  for(int i = n-1; i>=0; i--) {
    for(int j = n-1; j>=0; j--) {
      if(i == n-1 && j == n-1) {
        resolve[i][j] = 1;
        continue;
      }
      int nx = i + game[i][j];
      int ny = j + game[i][j];
      if(nx < n) {
        resolve[i][j] += resolve[nx][j];
      }
      if(ny < n) {
        resolve[i][j] += resolve[i][ny];
      }
    }
  }
  cout<<resolve[0][0];
  return 0;
}