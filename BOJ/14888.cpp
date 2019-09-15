#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

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
  vector<int> oper_permutation;
  for(int i=0; i<plus; i++) {
    oper_permutation.push_back(1);
  }
  for(int i=0; i<minus; i++) {
    oper_permutation.push_back(2);
  }
  for(int i=0; i<mul; i++) {
    oper_permutation.push_back(3);
  }
  for(int i=0; i<div; i++) {
    oper_permutation.push_back(4);
  }
  sort(oper_permutation.begin(),oper_permutation.end());

  int maxi=INT_MIN;
  int mini=INT_MAX;
  do {
    int result = numbers[0];
    for(int i=1; i<n; i++) {
      switch(oper_permutation[i-1]) {
        case 1:
          result+= numbers[i];
          break;
        case 2:
          result-= numbers[i];
          break;
        case 3:
          result*= numbers[i];
          break;
        case 4:
          result/= numbers[i];
          break;
      }
    }
    maxi = max(maxi,result);
    mini = min(mini,result);
  } while (next_permutation(oper_permutation.begin(),oper_permutation.end()));
  cout<<maxi<<endl<<mini;

  return 0;
}