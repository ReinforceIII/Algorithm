/* 1260 DFS와 BFS*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> v[1001];
bool visited[1001];
void dfs(int node) {
  visited[node] = true;
  cout<<node<<" ";
  for(int i=0; i<v[node].size(); i++) {
    int next = v[node][i];
    if(visited[next] == false) dfs(next);
  }
}
void bfs(int node) {
  queue<int> q;
  visited[node] = true;
  q.push(node);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    cout<<now<<" ";
    for(int i=0; i<v[now].size(); i++) {
      int next = v[now][i];
      if(visited[next] == false) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main() {
  int n,m,start;
  cin>>n>>m>>start;
  for(int i=0; i<m; i++) {
    int from,to;
    cin>>from>>to;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  for(int i=1; i<=n; i++) {
    sort(v[i].begin(),v[i].end());
  }
  dfs(start);
  cout<<"\n";
  memset(visited,false,sizeof(visited));
  bfs(start);
  cout<<"\n";
  return 0;
}