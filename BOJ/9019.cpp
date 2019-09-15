/* 9019 DSLR */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define MAX_SIZE 10000
using namespace std;


int main() {
  int t; cin>>t;
  while(t--) {
    int resolve[MAX_SIZE];
    pair<int,char> path[MAX_SIZE];
    int n,k;
    cin>>n>>k;
    queue<int> q;
    memset(resolve,-1,sizeof(resolve));
    q.push(n);
    resolve[n] = 0;
    while(!q.empty()) {
      int now = q.front();
      q.pop();

      if(now == k) {
        vector<char> p;
        while(now != n) {
          p.push_back(path[now].second);
          now = path[now].first;
        }
        for(auto i = p.rbegin(); i!= p.rend(); i++) {
          cout<<*i;
        }
        cout<<"\n";
        break;
      }

      //1. D
      int twice = (now*2)%10000;
      if(resolve[twice] == -1) {
        q.push(twice);
        resolve[twice] = resolve[now] + 1;
        path[twice].first = now;
        path[twice].second = 'D';
      }//2. S
      int minus = now - 1;
      if(minus < 0) minus = 9999;
      if(resolve[minus] == -1) {
        q.push(minus);
        resolve[minus] = resolve[now] + 1;
        path[minus].first = now;
        path[minus].second = 'S';
      }
      if(now != 0) {
        //L
        int left_shift = now;
        left_shift = (left_shift % 1000) * 10 + (left_shift / 1000);
        if(resolve[left_shift] == -1) {
          q.push(left_shift);
          resolve[left_shift] = resolve[now] + 1;
          path[left_shift].first = now;
          path[left_shift].second = 'L';
        }
        //R
        int right_shift = now;
        right_shift = right_shift/10 + (right_shift%10)*1000;
        if(resolve[right_shift] == -1) {
          q.push(right_shift);
          resolve[right_shift] = resolve[now] + 1;
          path[right_shift].first = now;
          path[right_shift].second = 'R';
        }
      }
      
    }
  }
  return 0;
}