/* 1748 수 이어 쓰기 1 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Nlen(int n) {
  int result =0;
  while(n) {
    result++;
    n /= 10;
  }
  return result;
}

int main() {
  long long n;
  cin>>n;
  long long result = 0;
  for(long long i=1; i<=n; i++) {
    result += Nlen(i);
  }
  cout<<result;
  return 0;
}