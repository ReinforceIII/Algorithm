/* 15649 N과 M (1) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;
bool check[10];
int sel[10];

void recur(int index, int n, int m) {
  if(index == m) {
    for(int i=0; i<m; i++) {
      cout<<sel[i];
      if(i != m -1) cout<<' ';
    }
    cout<<"\n";
    return;
  }
  for(int i=1; i<=n; i++) {
    if(check[i]) continue;
    check[i] = true; sel[index] = i;
    recur(index+1,n,m);
    check[i] = false;
  }
}


int main() {
  int n,m;
  cin>>n>>m;
  
  recur(0,n,m);
  return 0;
}