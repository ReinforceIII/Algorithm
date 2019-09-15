/* 12906 새로운 하노이 탑 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <limits.h>
#include <cstring>
#include <array>
#include <map>
#define STICK 3
using namespace std;

typedef array<string,STICK> tower;

int main(void) {
    tower t;
    for(int i=0; i<STICK; i++) {
        int cnt;
        cin>>cnt;
        if(cnt > 0) cin>>t[i];
        else t[i] = "";
    }
    //각각 원반이 몇개씩 있는지 조사.
    array<int,STICK> cnt_pris = {0,0,0};
    for(int i=0; i<STICK; i++) {
        for(int j=0; j<t[i].length(); j++) {
            cnt_pris[t[i][j] - 'A']++;
        }
    }
    map<tower,int> check;
    queue<tower> q;
    q.emplace(t);
    check[t] = 0;
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(int i=0; i<STICK; i++) {
            for(int j=0; j<STICK; j++) {
                if(i == j) continue;
                if(now[i].length() == 0) continue;
                tower next(now);
                next[j].push_back(next[i].back());
                next[i].pop_back();
                if(check.count(next) == 0) {
                    check[next] = check[now] + 1;
                    q.emplace(next);
                }
            }
        }
    }
    tower result;
    for(int i=0; i<STICK; i++) {
        for(int j=0; j<cnt_pris[i]; j++) {
            result[i] += char('A'+i);
        }
    }
    cout<< check[result];
    return 0;
}
