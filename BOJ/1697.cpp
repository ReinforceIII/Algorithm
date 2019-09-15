/* 1697 숨바꼭질 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 100001
using namespace std;

int resolve[MAX_SIZE];

int main() {
  int n,k;
  cin>>n>>k;
  queue<int> q;
  memset(resolve,-1,sizeof(resolve));
  q.push(n);
  resolve[n] = 0;
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    //1. 순간이동
    if(now*2 < MAX_SIZE) {
      if(resolve[now*2] == -1) {
        q.push(now*2);
        resolve[now*2] = resolve[now] + 1;
      }
    } //2. 뒤로한칸
    if(now -1 >= 0) {
      if(resolve[now-1] == -1) {
        q.push(now -1);
        resolve[now-1] = resolve[now] + 1;
      }
    } //3. 앞으로 한칸
    if(now +1 < MAX_SIZE) {
      if(resolve[now+1] == -1) {
        q.push(now + 1);
        resolve[now+1] = resolve[now] + 1;
      }
    }
  }
  
  cout<<resolve[k];
  return 0;
}