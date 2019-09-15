/* 14499 주사위 굴리기 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 20
int map[MAX_SIZE][MAX_SIZE];
int dice[7];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
using namespace std;
int main() {
  int n,m,x,y,k;
  cin>>n>>m>>x>>y>>k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[i][j];
    }
  }
  while(k--) {
    int dir;
    cin>>dir;
    dir--;
    int nx,ny;
    nx = x + dx[dir];
    ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    
    int temp = dice[1];
    switch(dir) {
      case 0: // east
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
        break;
      case 1: //west
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
        break;
      case 2: // north
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
        break;
      case 3: // south
      dice[1] = dice[2];
      dice[2] = dice[6];
      dice[6] = dice[5];
      dice[5] = temp;
      break;
    }
    x = nx; y = ny;
    if(map[x][y] == 0) map[x][y] = dice[6];
    else {
      dice[6] = map[x][y];
      map[x][y] = 0;
    }
    cout<<dice[1]<<"\n";
  }
  
  return 0;
}