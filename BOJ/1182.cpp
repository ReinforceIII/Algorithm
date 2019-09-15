#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n,s;
  cin>>n>>s;
  vector<int> num_list;
  for(int i=0; i<n; i++) {
    int temp;
    cin>>temp;
    num_list.push_back(temp);
  }
  
  int result = 0;
  for(int i=1; i<(1<<n); i++) {
    int sum = 0;
    for(int j=0; j<n; j++) {
      if(i&(1<<j)) sum += num_list[j];
    }
    if(sum == s) result++;
  }
  cout<<result;
  return 0;
}