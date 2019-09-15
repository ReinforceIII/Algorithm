/* 15685 드래곤 커브 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>

typedef std::pair<int,char> direction;
typedef std::pair<int,int> location;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

using namespace std;

vector<int> DragonCurve(int x, int y, int dir, int gen) {
  vector<int> ans = {dir};
  for(int i=1; i<=gen; i++) {
    vector<int> temp(ans);
    reverse(temp.begin(),temp.end());
    for(int &k : temp) {
      k = (k+1) % 4;
    }
    ans.insert(ans.end(),temp.begin(),temp.end());
  }
  return ans;
}
int main() {
  int n; cin>>n;
  vector<vector<bool>> map(101,vector<bool>(101,false));
  while(n--) {
    int x,y,dir,gen;
    cin>>y>>x>>dir>>gen;
    vector<int> dirs = DragonCurve(x,y,dir,gen);
    map[x][y] = true;
    for(int d : dirs) {
      x += dx[d];
      y += dy[d];
      map[x][y] = true;
    }
  }
  int result  = 0;
  for(int i=0; i<=99; i++) {
    for(int j=0; j<=99; j++) {
      if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) result++;
    }
  }
  cout<<result;
  return 0;
}