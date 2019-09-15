/* 14442번 벽 부수고 이동하기 2 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>

typedef std::tuple<int,int,int> loca_d;
int resolve[1001][1001][11];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

using namespace std;
int main(void) {
    int n,m,dr;
    cin>>n>>m>>dr;
    vector<string> pro_map(n);
    for(int i=0; i<n; i++) {
        cin>>pro_map[i];
    }
    queue<loca_d> q;
    q.emplace(0,0,0);
    resolve[0][0][0] = 1;
    while(!q.empty()) {
        int x,y,drill;
        tie(x,y,drill) = q.front(); q.pop();
        for(int k = 0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            if(pro_map[nx][ny] == '0' && resolve[nx][ny][drill] == 0) {
                resolve[nx][ny][drill] = resolve[x][y][drill] + 1;
                q.emplace(nx,ny,drill);
            }
            if(drill+1 <= dr && pro_map[nx][ny] == '1' && resolve[nx][ny][drill+1] == 0) {
                resolve[nx][ny][drill+1] = resolve[x][y][drill] + 1;
                q.emplace(nx,ny,drill+1);
            }
            
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<11; i++) {
        if(resolve[n-1][m-1][i] == 0) continue;
        ans = min(ans,resolve[n-1][m-1][i]);
    }
    if(ans == INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}
