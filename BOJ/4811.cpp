/* 4811 알약 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;
long long memo[31][31];

long long simul(int w,int h) {
    // w :온전한 한조각 개수 h : 반조각 개수
    if(memo[w][h] != -1) return memo[w][h];
    if(w == 0) return 1;
    if(h == 0) return memo[w][h] = simul(w-1,h+1);
    return memo[w][h] = simul(w-1,h+1) + simul(w,h-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    while(true) {
        int d;
        cin>>d;
        if(d == 0) break;
        cout<< simul(d,0)<<'\n';
    }
    return 0;
}