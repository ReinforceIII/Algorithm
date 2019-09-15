#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXI 20

using namespace std;
char opr[10];
int main() {
  int n;
  scanf("%d",&n);
  int S = 0;
  int x;
  while(n--) {
    scanf("%s",opr);
    if(!(strcmp(opr,"add"))) {
      scanf("%d",&x); x--;
      S = S | (1<<x);
    } else if(!(strcmp(opr,"remove"))){
      scanf("%d",&x); x--;
      S = S & ~(1<<x);
    } else if(!(strcmp(opr,"check"))){
      scanf("%d",&x); x--;
      if(S & (1<<x)) puts("1");
      else puts("0");
    } else if(!(strcmp(opr,"toggle"))){
      scanf("%d",&x); x--;
      S = S ^ (1<<x);
    } else if(!(strcmp(opr,"all"))){
      S = (1<<MAXI) -1;
    } else if(!(strcmp(opr,"empty"))){
      S = 0;
    }
  }
  return 0;
}