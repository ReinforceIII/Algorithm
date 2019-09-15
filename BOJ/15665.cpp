/* 15665 N과 M (11) */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;
int sel[10];
vector<int> num;
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
    sel[index] = i;
    recur(index+1,n,m);
  }
}


int main() {
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    int temp;
    cin>>temp;
    num.push_back(temp);
  }
  sort(num.begin(),num.begin()+n);
  num.erase(unique(num.begin(),num.end()),num.end());
  n = num.size();
  recur(0,n,m);
  return 0;
}