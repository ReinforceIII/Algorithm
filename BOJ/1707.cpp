/* 1707 이분그래프*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> graph[20001];
int color[20001];
void dfs(int node,int c) {
  color[node] = c;
  for(int i=0; i<graph[node].size(); i++) {
    int next = graph[node][i];
    if(color[next] == 0) dfs(next,3-c);
  }
}
int main() {
  int t;
  cin>>t;
  while(t--) {
    int v,e;
    cin>>v>>e;
    for(int i=1; i<=v; i++) {
      graph[i].clear();
      color[i] = 0;
    }
    for(int i=0; i<e; i++) {
      int from,to;
      cin>>from>>to;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    for(int i=1; i<=v; i++) {
      if(color[i] == 0) dfs(i,1);
    }
    bool result = true;
    for(int i=1; i<=v; i++) {
      for(int j=0; j<graph[i].size(); j++) {
        int k = graph[i][j];
        if(color[i] == color[k]) {
          result = false;
        }
      }
    }
  printf("%s\n", result ? "YES" : "NO");
  }
  return 0;
}