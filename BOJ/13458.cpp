/* 13458 시험감독 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> rooms(n);
    for(int i=0; i<n; i++) {
        cin>>rooms[i];
    }
    int m,s;
    cin>>m>>s;
    for(int i=0; i<n; i++) {
        if(rooms[i] - m < 0) rooms[i] = 0;
        else rooms[i] -= m;
    }
    long long ans = n;
    for(int i = 0; i<n; i++) {
        if(rooms[i]%s == 0) ans += rooms[i]/s;
        else ans += rooms[i]/s + 1;
    }
    cout<<ans;

    return 0;
}