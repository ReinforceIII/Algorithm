/* 2290 LCD Test */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>

using namespace std;
int eight_segment[10][7] = {
  {1,1,1,0,1,1,1},
  {0,0,1,0,0,1,0},
  {1,0,1,1,1,0,1},
  {1,0,1,1,0,1,1},
  {0,1,1,1,0,1,0},
  {1,1,0,1,0,1,1},
  {1,1,0,1,1,1,1},
  {1,0,1,0,0,1,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

int main() {
  int s;
  string output;
  cin>>s>>output;
  for(int i=0; i<5; i++) {
    if(i == 0 || i == 2 || i == 4) {
      for(int n = 0; n<output.size(); n++) {
        int now = output[n] - '0';
        if (n != 0) cout<<' ';    //숫자사이 공백
        cout<<' ';  //세로줄 자리
        if((i == 0 && eight_segment[now][0]) || 
           (i == 2 && eight_segment[now][3]) ||
           (i == 4 && eight_segment[now][6])) {
          for(int t = 0; t<s; t++) cout<<'-';
        } else {
          for(int t = 0; t<s; t++) cout<<' ';
        }
        cout<<' '; //세로줄 자리
      }
      cout<<'\n';
    }
    else {
      for(int line = 0; line<s; line++) {
        for(int n = 0; n<output.size(); n++) {
          int now = output[n] - '0';
          if (n != 0) cout<<' ';    //숫자사이 공백
          if((i == 1 && eight_segment[now][1]) ||
            (i == 3 && eight_segment[now][4])) cout<<'|';
          else cout<<' ';
          for(int t =0; t<s; t++) cout<<' ';
          if((i == 1 && eight_segment[now][2]) ||
             (i == 3 && eight_segment[now][5])) cout<<'|';
          else cout<<' ';
        }
        cout<<'\n';
      }
    }
  }
  return 0;
}