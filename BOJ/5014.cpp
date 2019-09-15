/* 5014번 스타트링크 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

int main(void) {
    int F,S,G,U,D;
    cin>>F>>S>>G>>U>>D;
    if(S > G && D == 0) {
        cout<<"use the stairs";
        return 0;
    } else if(S<G && U == 0) {
        cout<<"use the stairs";
        return 0;
    } else if(S == G) {
        cout<<"0";
        return 0;
    }

    vector<int> building(F+1,INT_MAX);
    queue<int> q;
    q.push(S);
    building[S] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now+U <= F && building[now+U] > building[now]+1) {
            building[now+U] = building[now]+1;
            q.push(now+U);
        }
        if(now-D >= 1 && building[now-D] > building[now]+1) {
            building[now-D] = building[now]+1;
            q.push(now-D);
        }
    }
    if(building[G] == INT_MAX) cout<<"use the stairs";
    else cout<<building[G];
    return 0;
}
