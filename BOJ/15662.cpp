/* 15662 톱니바퀴(2) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int main() {
  int count;
  cin>>count;
  vector<string> wheel(count);
  for(int i=0; i<count; i++) {
    cin>>wheel[i];
  }
  int k; cin>>k;
  while(k--) {
    int n,dir; //dir : -1 counter-clockwise // 1 clockwise
    cin>>n>>dir;
    n--;
    vector<int> direction(count);
    direction[n] = dir;
    for(int i=n-1; i>=0; i--) {
      if(wheel[i][2] != wheel[i+1][6]) {
        direction[i] = -direction[i+1];
      } else break;
    }
    for(int i= n+1; i<count; i++) {
      if(wheel[i-1][2] != wheel[i][6]) {
        direction[i] = -direction[i-1];
      } else break;
    }
    for(int i=0; i<count; i++) {
      if(direction[i] == 0) continue;
      else if(direction[i] == 1) {
        string temp = wheel[i].substr(0,7);
        string ts;
        ts+=wheel[i][7];
        ts.append(temp);
        wheel[i] = ts;
      } else if(direction[i] == -1) {
        char temp = wheel[i][0];
        string ts = wheel[i].substr(1,7);
        ts += temp;
        wheel[i] = ts;
      }
    }
  }
  int result = 0;
  for(int i=0; i<count; i++) {
    if(wheel[i][0] == '1') result++;
  }
  cout<< result<<"\n";
  return 0;
}