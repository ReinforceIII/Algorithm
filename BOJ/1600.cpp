/* 1600번 말이 되고픈 원숭이 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>
#include <cstring>

typedef std::tuple<int,int,int> loca_j;
int resolve[201][201][31];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int kdx[8] = {-1,-2,-2,-1, 1, 2,2,1};
int kdy[8] = {-2,-1, 1, 2,-2,-1,1,2};

using namespace std;
int main(void) {
    int kn; cin>>kn;
    int n,m; cin>>m>>n;
    vector<vector<int>> pro_map(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>pro_map[i][j];
        }
    }
    memset(resolve,-1,sizeof(resolve));
    queue<loca_j> q;
    q.emplace(0,0,0);
    resolve[0][0][0] = 0;
    while(!q.empty()) {
        int x,y,jump;
        tie(x,y,jump) = q.front(); q.pop();
        for(int k = 0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            if(pro_map[nx][ny] == 0 && resolve[nx][ny][jump] == -1) {
                resolve[nx][ny][jump] = resolve[x][y][jump] + 1;
                q.emplace(nx,ny,jump);
            }            
        }
        if(jump+1 <= kn) {
            for(int k=0; k<8; k++) {
                int nx = x+kdx[k];
                int ny = y+kdy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
                if(pro_map[nx][ny] == 0 && resolve[nx][ny][jump+1] == -1) {
                    resolve[nx][ny][jump+1] = resolve[x][y][jump] + 1;
                    q.emplace(nx,ny,jump+1);
                }   
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<31; i++) {
        if(resolve[n-1][m-1][i] == -1) continue;
        ans = min(ans,resolve[n-1][m-1][i]);
    }
    if(ans == INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}
