/* 6064 카잉달력 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) return a;
  else return gcd(b, a%b);
}
int lcm(int a, int b) {
  return a*b /gcd(a,b);
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    int M,N,x,y;
    cin>>M>>N>>x>>y;
    int last = lcm(M,N);
    int result = -1;
    int now = x;
    do {
      if (now%N == y) {
        result = now;
        break;
      } else now+=M;
    } while(now <= last);
    now = y;
    do {
      if(now%M == x) {
        result = now;
        break;
      } else now+=N;
    } while(now<= last);
    cout<<result<<"\n";
  }
  return 0;
}