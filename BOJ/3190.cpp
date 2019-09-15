/* 3190 뱀 */
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

int map[100][100];

using namespace std;
int main() {
  int n; cin>>n;
  int apple; cin>>apple;
  for(int i=0; i<apple; i++) {
    int x,y; cin>>x>>y;
    map[x-1][y-1] = 3;
  }
  int d; cin>>d;
  queue<direction> waiting;
  for(int i=0; i<d; i++) {
    int t;
    char dir;
    cin>>t>>dir;
    waiting.emplace(t,dir);
  }
  int wt = waiting.front().first;
  int now = 0;
  int x = 0;
  int y = 0;
  int head = 0;
  list<location> snake;
  snake.emplace_front(x,y);
  while(true) {
    now++;
    x += dx[head];
    y += dy[head];
    location pos = make_pair(x,y);
    if(x < 0 || x >= n || y < 0 || y >= n) break;
    if(find(snake.begin(),snake.end(),pos) != snake.end()) break;

    snake.emplace_front(x,y);
    if(map[x][y] != 3) {
      snake.pop_back();
    } else {      
      map[x][y] = 0;
    }

    if(now == wt) {
      char lr = waiting.front().second;
      if(lr == 'L') head = (head + 1) % 4;
      else head = (head + 3) % 4;
      waiting.pop();
      wt = waiting.front().first;
    }
  }
  cout<<now;
  return 0;
}