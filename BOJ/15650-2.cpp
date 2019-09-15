/* 15650 N과 M (2) 두번째 방법*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int sel[10];

void recur(int index,int selected, int n, int m) {
  if(selected == m) {
    for(int i=0; i<m; i++) {
      cout<<sel[i]<<' ';
    }
    cout<<"\n";
    return ;
  }
  if(index>n) return;
  sel[selected] = index;
  recur(index+1, selected+1,n,m);
  sel[selected] = 0;
  recur(index+1,selected,n,m);

}

int main() {
  int n,m;
  cin>>n>>m;
  
  recur(1,0,n,m);
  return 0;
}