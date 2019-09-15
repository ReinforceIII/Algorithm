/* 15486 퇴사 2 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
int answer = 0;
int T[1500000];
int P[1500000];
int memo[1500000];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>T[i]>>P[i];
    }
    for(int i=0; i<n; i++) {
        memo[i+T[i]] = max(memo[i+T[i]],memo[i]+P[i]);
        memo[i+1] = max(memo[i+1],memo[i]);
    }
    cout<<memo[n]<<"\n";
    return 0;
}