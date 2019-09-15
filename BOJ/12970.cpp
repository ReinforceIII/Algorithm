/* 12970 AB */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;

bool memo[51][51][51][1226];
int n,k;
char ans[51];

bool dp(int len, int a, int b, int p) {
    if(len == n) {
        if(p == k) return true;
        else return false;
    }
    bool &now = memo[len][a][b][p];
    if(now == true) return false;
    now = true;
    ans[len] = 'A';
    if(dp(len+1,a+1,b,p) == true) return true;

    ans[len] = 'B';
    if(dp(len+1,a,b+1,p+a) == true) return true;

    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>k;

    if(dp(0,0,0,0)) cout<<ans;
    else cout<<-1;
    return 0;
}