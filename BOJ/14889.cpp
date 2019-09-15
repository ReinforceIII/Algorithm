/* 14889 스타트와 링크 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int main() {
  int n; cin>>n;
  vector<vector<int>> abil(n,vector<int>(n));
  vector<int> people;
  vector<vector<int>> teamlist;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>abil[i][j];
    }
    people.push_back(i);
  }
  vector<int> kuji;
  for(int i=0; i<n/2; i++) {
    kuji.push_back(0);
    kuji.push_back(1);
  }
  sort(kuji.begin(),kuji.end());
  int mini = INT_MAX;
  do {
    vector<int> teamA;
    vector<int> teamB;
    for(int i=0; i<n; i++) {
      if(kuji[i] == 0) teamA.push_back(people[i]);
      if(kuji[i] == 1) teamB.push_back(people[i]);
    }
    teamlist.push_back(teamA);
    teamlist.push_back(teamB);

    int a_temp = 0;
    int b_temp = 0;
    for(int i=0; i<teamA.size(); i++) {
      for(int j=0; j<teamA.size(); j++) {
        a_temp += abil[teamA[i]][teamA[j]];
        b_temp += abil[teamB[i]][teamB[j]];
      }
    }
    int temp_result = abs(a_temp - b_temp);
    mini = min(mini,temp_result);
  } while(next_permutation(kuji.begin(),kuji.end()));
  cout<<mini;
  return 0;
}