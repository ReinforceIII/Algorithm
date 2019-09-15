/* 1525 퍼즐 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int main() {
  string puzzle;
  map<string,int> m;
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      string temp;
      cin>>temp;
      puzzle += temp;
    }
  }
  queue<string> q;
  q.push(puzzle);
  m[puzzle] = 0;
  int result = -1;
  while(!q.empty()) {
    string now = q.front(); q.pop();
    if(now == "123456780") {
      result = m[now];
      break;
    }
    int loca = now.find("0");
    int x = loca/3; int y = loca%3;
    for(int k=0; k<4; k++) {
      string change = now;
      int nx = x + dx[k]; int ny = y + dy[k];
      if(0 > nx || nx >= 3 || 0 > ny || ny >= 3) continue;
      char temp = now.at(nx*3+ny);
      change[nx*3+ny] = now[x*3+y];
      change[x*3 +y] = temp;
      if(m[change] == 0) {
        q.push(change);
        int next = (m.find(now)->second) + 1;
        m[change] = next;
      }
    }

  }
  cout<<result;
  return 0;
}