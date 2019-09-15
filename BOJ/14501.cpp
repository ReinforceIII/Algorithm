#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
int answer = 0;

//day 선택할지 말지 결정하는 날 , sum 지금까지의 금액합., deadline : 퇴사일
void recur(int day,int sum, int deadline, vector<int> &t, vector<int> &p) {
  if(day == deadline) {
    if(answer < sum) answer = sum;
    return ;
  }
  if(day> deadline) return;
  recur(day+1,sum,deadline,t,p);
  recur(day+t[day],sum+p[day],deadline,t,p);

}

int main() {
  int n;
  cin>>n;
  vector<int> T(n+1);
  vector<int> P(n+1);
  for(int i=1; i<=n; i++) {
      int t1,t2;
      cin>>t1>>t2;
      T[i] = t1;
      P[i] = t2;
  }
  recur(1,0,n+1,T,P);
  cout<<answer<<"\n";
  return 0;
}