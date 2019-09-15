/* 12969 ABC */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;
bool memo[31][31][31][436];
int n,k;
char ans[31];

bool dp(int len, int A, int B, int p) {
    if(len == n) {
        if(p == k) return true;
        else return false;
    }
    if(memo[len][A][B][p]) return false;
    memo[len][A][B][p] = true;
    ans[len] = 'A';
    if(dp(len+1,A+1,B,p)) return true;

    ans[len] = 'B';
    if(dp(len+1,A,B+1,p+A)) return true;

    ans[len] = 'C';
    if(dp(len+1,A,B,p+A+B)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>k;

    if(dp(0,0,0,0)) cout<<ans;
    else cout<<-1;

    return 0;
}