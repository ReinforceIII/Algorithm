#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
int maxi = INT_MIN;
int mini = INT_MAX;

void recur(vector<int> &n, int index, int result, int plus, int minus, int mul, int div) {
  int s = n.size();
  if(index == s) {
    maxi = max(maxi,result);
    mini = min(mini,result);
    return;
  }
  if(plus>0) recur(n,index+1,result+n[index],plus-1,minus,mul,div);
  if(minus>0) recur(n,index+1,result-n[index],plus,minus-1,mul,div);
  if(mul>0) recur(n,index+1,result*n[index],plus,minus,mul-1,div);
  if(div>0) recur(n,index+1,result/n[index],plus,minus,mul,div-1);
  
  return;
}

int main() {
  int n;
  cin>>n;
  vector<int> numbers;
  for(int i=0; i<n; i++) {
    int temp;
    cin>>temp;
    numbers.push_back(temp);
  }
  int plus,minus,mul,div;
  cin>>plus>>minus>>mul>>div;
  recur(numbers,1,numbers[0],plus,minus,mul,div);
  cout<<maxi<<"\n"<<mini;
  return 0;
}