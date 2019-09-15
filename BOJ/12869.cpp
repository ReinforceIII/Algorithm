/* 12869 뮤탈리스크 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;
int memo[61][61][61];

int dp(int a, int b, int c) {
    if(a < 0) return dp(0,b,c);
    if(b < 0) return dp(a,0,c);
    if(c < 0) return dp(a,b,0);
    if(a == 0 && b == 0 && c == 0) return 0;
    int &result = memo[a][b][c];
    if(result != -1) return result;
    result = INT_MAX;
    vector<int> mutal = {1,3,9};
    do {
        result = min(result,dp(a-mutal[0],b-mutal[1],c-mutal[2]));
    } while (next_permutation(mutal.begin(),mutal.end()));
    result++;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int SCV[3] = {0,0,0};
    for(int i=0; i<n; i++) cin>>SCV[i];
    memset(memo,-1,sizeof(memo));
    cout<<dp(SCV[0],SCV[1],SCV[2]);
    return 0;
}