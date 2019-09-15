/* 2933 미네랄 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>

using namespace std;
typedef pair<int,int> location;
int r,c;
char map[110][110];
bool check[110][110];
vector<location> group;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void floodfill(int x, int y) {
  if(map[x][y] == '.') return;
  if(check[x][y]) return;
  check[x][y] = true;
  group.emplace_back(x,y);
  for(int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if( 0<= nx && nx < r && 0 <= ny && ny < c) floodfill(nx,ny);
  }
}
void simulate() {
  memset(check, false, sizeof(check));
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      if(map[i][j] == '.') continue;
      if(check[i][j]) continue;
      group.clear();
      floodfill(i,j);
      vector<int> bottom(c,-1);
      for(auto l : group) {
        bottom[l.second] = max(bottom[l.second],l.first);
        map[l.first][l.second] = '.';
      }
      int abyss = r;
      for(int a, b = 0; b<c; b++) {
        if(bottom[b] == -1) continue;
        for(a = bottom[b]; i<r && map[a][b] == '.'; a++);
        abyss = min(abyss,a-bottom[b]-1);
      }
      for(auto l : group) {
        l.first += abyss;
        map[l.first][l.second] = 'x';
        check[l.first][l.second] = true;
      }
    }
  }
}
int main() {
  cin>>r>>c;
  for(int i =0; i<r; i++) {
    for(int j =0; j<c; j++) {
      cin>>map[i][j];
    }
  }
  int times;
  cin>>times;
  for(int i=1; i<=times; i++) {
    int floor; cin>>floor;
    floor = r - floor;
    if(i%2 == 1) {
      for(int k = 0; k<c; k++) {
        if(map[floor][k] == 'x') {
          map[floor][k] = '.';
          break;
        }
      }
    } else {
      for(int k = c-1; k >= 0; k--) {
        if(map[floor][k] == 'x') {
          map[floor][k] = '.';
          break;
        }
      }
    }
    simulate();
  }
  for(int i=0; i<r; i++) {
    cout<<map[i]<<"\n";
  }
  return 0;
}