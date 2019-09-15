/* 15651 N과 M (3) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;
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
    sel[index] = i;
    recur(index+1,n,m);
  }
}


int main() {
  int n,m;
  cin>>n>>m;
  recur(0,n,m);
  return 0;
}