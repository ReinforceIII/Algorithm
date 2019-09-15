/* 14890 경사로 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

bool stimulate(vector<int> r, int ladder) {
  int n = r.size();
  vector<bool> c(n, false);

  for(int i=1; i<n; i++) {
    if(r[i-1] != r[i]) {
      //경사로 놓기
      int diff = abs(r[i]-r[i-1]);
      if(diff != 1) return false;

      if(r[i-1] < r[i]) {
        for(int k=1; k<=ladder; k++) {
          if(i-k < 0) return false;
          if(r[i-1] != r[i-k]) return false;
          if(c[i-k]) return false;
          c[i-k] = true;
        }
      } else {
        for(int k=0; k<ladder; k++) {
          if(i+k >= n) return false;
          if(r[i] != r[i+k]) return false;
          if(c[i+k]) return false;
          c[i+k] = true;
        }
      }
    }
  }
  return true;
}

int main() {
  int n,lad;
  cin>>n>>lad;
  vector<vector<int>> map(n,vector<int>(n));
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>map[i][j];
    }
  }
  int result = 0;
  for(int i=0; i<n; i++) {
    vector<int> road = map[i];
    if(stimulate(road,lad)) result++;
  }
  for(int i=0; i<n; i++) {
    vector<int> road(n);
    for(int j=0; j<n; j++) {
      road[j] = map[j][i];
    }
    if(stimulate(road,lad)) result++;
  }
  cout<<result;
  return 0;
}