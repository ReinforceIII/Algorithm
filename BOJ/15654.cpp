/* 15654 N과 M (5) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;
bool check[10];
int sel[10];
int num[10];
void recur(int index, int n, int m) {
  if(index == m) {
    for(int i=0; i<m; i++) {
      cout<<num[sel[i]];
      if(i != m -1) cout<<' ';
    }
    cout<<"\n";
    return;
  }
  for(int i=0; i<n; i++) {
    if(check[i]) continue;
    check[i] = true; sel[index] = i;
    recur(index+1,n,m);
    check[i] = false;
  }
}


int main() {
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>> num[i];
  }
  sort(num,num+n);
  recur(0,n,m);
  return 0;
}