/* 14503 로봇 청소기 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int map[51][51];

using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  int x,y,dir;
  cin>>x>>y>>dir;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[i][j];
    }
  }
  while(true) {
    map[x][y] = 2;

    if(map[x-1][y] != 0 && map[x+1][y] != 0 && map[x][y+1] != 0 && map[x][y-1] != 0) {
      if(map[x-dx[dir]][y-dy[dir]] == 1) break;
      else {
        x -= dx[dir];
        y -= dy[dir];
      }
    } else {
      dir = (dir + 3) % 4;
      if(map[x+dx[dir]][y+dy[dir]] == 0) {
        x+=dx[dir];
        y+=dy[dir];
      }
    }
  }
  int result = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(map[i][j] == 2) result++;
    }
  }
  cout<<result;
  return 0;
}