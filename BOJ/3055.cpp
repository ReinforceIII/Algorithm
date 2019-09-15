/* 3055 탈출 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_SIZE 50
using namespace std;

char map[MAX_SIZE][MAX_SIZE];
int resolve[MAX_SIZE][MAX_SIZE];
int water[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int main() {
  int r,c;
  cin>>r>>c;
  int rx,ry;
  queue<pair<int,int>> wq;
  queue<pair<int,int>> mq;
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      scanf("%1s",&map[i][j]);
      water[i][j] = -1;
      resolve[i][j] = -1;
      if(map[i][j] == 'S') {
        mq.push(make_pair(i,j));
        resolve[i][j] = 0;
      }else if(map[i][j] == '*') {
        wq.push(make_pair(i,j));
        water[i][j] = 0;
      }else if(map[i][j] == 'D') {
        rx = i;
        ry = j;
      }
    }
  }
  //1. water맵 작성
  while(!wq.empty()) {
    int x,y;
    x = wq.front().first;
    y = wq.front().second;
    wq.pop();

    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < r && 0 <= ny && ny < c) {
        if(water[nx][ny] == -1) {
          if(map[nx][ny] == 'D' || map[nx][ny] == 'X') continue;
          water[nx][ny] = water[x][y] + 1;
          wq.push(make_pair(nx,ny));
        }
      }
    }
  }
  //2. 이동맵 작성
  while(!mq.empty()) {
    int x,y;
    x = mq.front().first;
    y = mq.front().second;
    mq.pop();

    for(int i=0; i<4; i++) {
      int nx = x + dx[i]; int ny = y + dy[i];
      if(0 <= nx && nx < r && 0 <= ny && ny < c) {
        if(resolve[nx][ny] == -1) {
          if(map[nx][ny] == 'X') continue;
          if(water[nx][ny] != -1 && resolve[x][y] + 1 >= water[nx][ny]) continue;
          resolve[nx][ny] = resolve[x][y] + 1;
          mq.push(make_pair(nx,ny));
        }
      }
    }
  }

  if(resolve[rx][ry] == -1) cout<<"KAKTUS";
  else cout<<resolve[rx][ry];
  return 0;
}