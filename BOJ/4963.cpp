/* 4963 섬의개수 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int w,h;
int map[50][50];
int resolve[50][50];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
void bfs(int x, int y, int cnt) {
  queue<pair<int,int>> q;
  resolve[x][y] = cnt;
  q.push(make_pair(x,y));
  while(!q.empty()) {
    x = q.front().first; y = q.front().second; q.pop();
    for(int i=0; i<8; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < h && 0 <= ny && ny < w) {
        if(map[nx][ny] == 1 && resolve[nx][ny] == 0) {
          q.push(make_pair(nx,ny));
          resolve[nx][ny] = cnt;
        }
      }
    }
  }
}

int main() {
  while(true) {
    cin>>w>>h;
    if( w == 0 && h == 0 ) break;
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        int temp;
        cin>>temp;
        map[i][j] = temp;
        resolve[i][j] = 0;
      }
    }

    int cnt = 0;
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        if(map[i][j] == 1 && resolve[i][j] == 0) {
          bfs(i,j,++cnt);
        }
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}