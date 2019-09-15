/* 14238 출근 기록 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;
int memo[51][51][51][3][3];

int dp(int na, int nb, int nc, int p1, int p2) {
    int &now = memo[na][nb][nc][p1][p2];
    if(na+nb+nc == 0) return now = 1;
    
    if(now != -1) return now;

    if(na > 0 && dp(na-1,nb,nc,0,p1) == 1) return now = 1;

    if(nb > 0 && p1 != 1) {
        if(dp(na,nb-1,nc,1,p1) == 1) return now = 1;
    }
    
    if(nc > 0 && p1 != 2 && p2 != 2) {
        if(dp(na,nb,nc-1,2,p1) == 1) return now = 1;
    }
    return now = 0;
}

string getAttend(int na, int nb, int nc, int p1, int p2) {
    if(na+nb+nc == 0) return "";

    if(na > 0 && dp(na-1,nb,nc,0,p1) == 1) return "A" + getAttend(na-1,nb,nc,0,p1);

    if(nb > 0 && p1 != 1) {
        if(dp(na,nb-1,nc,1,p1) == 1) return "B" + getAttend(na,nb-1,nc,1,p1);
    }
    
    if(nc > 0 && p1 != 2 && p2 != 2) {
        if(dp(na,nb,nc-1,2,p1) == 1) return "C" + getAttend(na,nb,nc-1,2,p1);
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int cnt[3] = {0,0,0};
    for(int i=0; i<s.length(); i++) cnt[s[i]-'A'] += 1;

    memset(memo,-1,sizeof(memo));
    int result = dp(cnt[0],cnt[1],cnt[2],0,0);
    if(result == 0) cout<< -1<<'\n';
    else cout<<getAttend(cnt[0],cnt[1],cnt[2],0,0)<<'\n';

    return 0;
}