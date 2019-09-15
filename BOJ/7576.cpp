/* 2178 미로 탐색 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int resolve[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  int n,m;
  cin>>m>>n;
  queue<pair<int,int>> q;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%d",&map[i][j]);
      resolve[i][j] = -1;
      if(map[i][j] == 1) {
        q.push(make_pair(i,j));
        resolve[i][j] = 0;
      }
    }
  }
  int x,y;
  while(!q.empty()) {
    x = q.front().first; y = q.front().second; q.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m) {
        if(map[nx][ny] == 0 && resolve[nx][ny] == -1) {
          q.push(make_pair(nx,ny));
          resolve[nx][ny] = resolve[x][y] + 1;
        }
      }
    }
  }
  int ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(map[i][j]==0 && resolve[i][j] == -1) {
        ans = -1;
        break;
      }
      else {
        if(ans < resolve[i][j]) ans = resolve[i][j];
      }
    }
    if(ans == -1) break;
  }
  cout<<ans;
  return 0;
}