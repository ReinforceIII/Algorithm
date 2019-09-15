#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int recur(int sum, int n) {
  if(sum>n) return 0;
  if(sum==n) return 1;
  int now = 0;
  for(int i=1; i<=3; i++) {
    now += recur(sum+i,n);
  }
  return now;
}

int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    int goal;
    cin>>goal;
    int result = recur(0,goal);
    cout<<result<<endl;
  }
  return 0;
}