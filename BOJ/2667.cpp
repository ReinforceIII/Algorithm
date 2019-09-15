/* 2667 단지번호붙이기 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int map[25][25];
int resolve[25][25];
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int x, int y, int cnt) {
  queue<pair<int,int>> q;
  resolve[x][y] = cnt;
  q.push(make_pair(x,y));
  while(!q.empty()) {
    x = q.front().first; y = q.front().second; q.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < n) {
        if(map[nx][ny] == 1 && resolve[nx][ny] == 0) {
          q.push(make_pair(nx,ny));
          resolve[nx][ny] = cnt;
        }
      }
    }
  }
}

int main() {
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf("%1d",&map[i][j]);
    }
  }
  int cnt = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(map[i][j] == 1 && resolve[i][j] == 0) {
        bfs(i,j,++cnt);
      }
    }
  }
  vector<int> hsize(cnt+1);
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(resolve[i][j] != 0) hsize[resolve[i][j]]++;
    }
  }
  cout<<cnt<<endl;
  sort(hsize.begin()+1,hsize.begin()+1+cnt);
  for(int i=1; i<hsize.size(); i++) {
    cout<<hsize[i]<<endl;
  }
  return 0;
}