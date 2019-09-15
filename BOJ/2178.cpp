/* 2178 미로 탐색 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 101
using namespace std;

int n,m;
int map[MAX_SIZE][MAX_SIZE];
int resolve[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int x, int y) {
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  while(!q.empty()) {
    x = q.front().first; y = q.front().second; q.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m) {
        if(map[nx][ny] == 1 && resolve[nx][ny] == 0) {
          q.push(make_pair(nx,ny));
          resolve[nx][ny] = resolve[x][y] + 1;
        }
      }
    }
  }
}

int main() {
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%1d",&map[i][j]);
    }
  }
  resolve[0][0] = 1;
  bfs(0,0);
  cout<<resolve[n-1][m-1];
  return 0;
}