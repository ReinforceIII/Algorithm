/* 15657 N과 M (8) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int sel[10];
int num[10];
void recur(int index,int start, int n, int m) {
  if(index == m) {
    for(int i=0; i<m; i++) {
      cout<<num[sel[i]];
      if(i != m-1) cout<<' ';
    }
    cout<<"\n";
    return;
  }
  for(int i=start; i<n; i++) {
    sel[index] = i;
    recur(index+1,i,n,m);
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
  return 0;
}