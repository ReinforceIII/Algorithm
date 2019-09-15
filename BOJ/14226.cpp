/* 14226 이모티콘 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001
using namespace std;

int resolve[MAX_SIZE][MAX_SIZE];

int main() {
  int S;
  cin>>S;
  queue<pair<int,int>> q;
  memset(resolve,-1,sizeof(resolve));
  q.push(make_pair(1,0));
  resolve[1][0] = 0;
  while(!q.empty()) {
    int imo = q.front().first;
    int clip = q.front().second;
    q.pop();
    //1. 클립보드 저장
    if(resolve[imo][imo] == -1) {
      resolve[imo][imo] = resolve[imo][clip] + 1;
      q.push(make_pair(imo,imo));
    } //2. 클립보드에서 붙여넣기
    if(imo+clip <= S && resolve[imo+clip][clip] == -1) {
      resolve[imo+clip][clip] = resolve[imo][clip] + 1;
      q.push(make_pair(imo+clip,clip));
    } //3. 하나 삭제
    if(imo-1 >=0 && resolve[imo-1][clip] == -1) {
      resolve[imo-1][clip] = resolve[imo][clip] + 1;
      q.push(make_pair(imo-1,clip));
    }
  }
  int ans = -1;
  for(int i=0; i<=S; i++) {
    if(resolve[S][i] != -1) {
      if(ans == -1 || ans > resolve[S][i]) ans = resolve[S][i];
    }
  }
  cout<<ans;
  return 0;
}