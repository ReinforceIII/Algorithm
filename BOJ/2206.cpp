/* 2206 벽 부수고 이동하기 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define MAX_SIZE 1001
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
// 0: 안부순상태 1: 부순상태
int resolve[MAX_SIZE][MAX_SIZE][2];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int main() {
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%1d",&map[i][j]);
    }
  }
  queue<tuple<int,int,int>> q;
  q.push(make_tuple(0,0,0));
  resolve[0][0][0] = 1;
  while(!q.empty()) {
    int x,y,z;
    tie(x,y,z) = q.front();
    q.pop();

    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m) {
        if(map[nx][ny] == 0 && resolve[nx][ny][z] == 0) {
          resolve[nx][ny][z] = resolve[x][y][z] + 1;
          q.push(make_tuple(nx,ny,z));
        }
        if(z == 0 && resolve[nx][ny][z+1] == 0) {
          resolve[nx][ny][z+1] = resolve[x][y][z] + 1;
          q.push(make_tuple(nx,ny,z+1));
        }
      }
    }
  }
  if (resolve[n-1][m-1][0] != 0 && resolve[n-1][m-1][1] != 0) {
        cout << min(resolve[n-1][m-1][0], resolve[n-1][m-1][1]);
    } else if (resolve[n-1][m-1][0] != 0) {
        cout << resolve[n-1][m-1][0];
    } else if (resolve[n-1][m-1][1] != 0) {
        cout << resolve[n-1][m-1][1];
    } else {
        cout << -1;
    }
  return 0;
}