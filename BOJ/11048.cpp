/* 11048 이동하기 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 1000

int dx[3] = {1,0,1};
int dy[3] = {0,1,1};
typedef std::pair<int,int> xy;
int cmap[MAX_SIZE][MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE];
using namespace std;

int main() {
  int n,m; cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>cmap[i][j];
      memo[i][j] = 0;
    }
  }
  int temp = 0;
  for(int i=0; i<n; i++) {
    temp += cmap[i][0];
    memo[i][0] = temp;
  }
  int temp2 = 0;
  for(int i=0; i<m; i++) {
    temp2 += cmap[0][i];
    memo[0][i] = temp2;
  }

  for(int i=1; i<n; i++) {
    for(int j=1; j<m; j++) {
      memo[i][j] = max(max(memo[i][j-1],memo[i-1][j]),memo[i-1][j-1]) + cmap[i][j];
    }
  }
  cout<<memo[n-1][m-1];
  return 0;
}