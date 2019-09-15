/* 15664 N과 M (10) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;
int sel[10];
int num[10];
vector<vector<int>> d;
void recur(int index, int start, int n, int m) {
  if(index == m) {
    vector<int> temp;
    for(int i=0; i<m; i++) {
      temp.push_back(num[sel[i]]);
    }
    d.push_back(temp);
    return;
  }
  for(int i=start; i<n; i++) {
    sel[index] = i;
    recur(index+1,i+1,n,m);
  }
}

int main() {
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>> num[i];
  }
  sort(num,num+n);
  recur(0,0,n,m);
  sort(d.begin(),d.end());
  d.erase(unique(d.begin(),d.end()),d.end());
  for(auto &v : d) {
    for(int i=0; i<m; i++) {
      cout<<v[i];
      if(i != m-1) cout<<' ';
    }
    cout<<"\n";
  }
  return 0;
}
