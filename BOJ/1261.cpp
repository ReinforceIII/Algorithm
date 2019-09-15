/* 1261 알고스팟 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
#define MAX_SIZE 101
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int resolve[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int main() {
  int n,m;
  cin>>m>>n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf("%1d",&map[i][j]);
      resolve[i][j] = -1;
    }
  }
  deque<pair<int,int>> q;
  q.push_back(make_pair(0,0));
  resolve[0][0] = 0;
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();

    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m) {
        if(resolve[nx][ny] == -1) {
          if(map[nx][ny] == 0) {
            q.push_front(make_pair(nx,ny));
            resolve[nx][ny] = resolve[x][y];
          } else {
            q.push_back(make_pair(nx,ny));
            resolve[nx][ny] = resolve[x][y] + 1;
          }
        }
      }
    }
    
  }
  
  cout<<resolve[n-1][m-1];
  return 0;
}