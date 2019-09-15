/* 2234번 성곽 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>
#include <cstring>

using namespace std;

typedef pair<int,int> loca;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int pro_map[50][50];
int resolve[50][50];
int room[50*50];
int n,m;

int bfs(int i, int j, int rooms) {
    queue<loca> q;
    resolve[i][j] = rooms;
    q.emplace(i,j);
    int result = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        result++;
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
            if(resolve[nx][ny] != 0) continue;
            if(pro_map[x][y] & (1<<k)) continue;
            q.emplace(nx,ny);
            resolve[nx][ny] = rooms;
        }
    }
    return result;
}


int main(void) {
    cin>>m>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>pro_map[i][j];
        }
    }
    int rooms = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(resolve[i][j] == 0) {
                rooms++;
                room[rooms] = bfs(i,j,rooms);
            }
        }
    }
    cout<<rooms<<'\n';
    int bigg = 0;
    for(int i=1; i<=rooms; i++) {
        bigg = max(bigg,room[i]);
    }
    cout<<bigg<<'\n';

    int combinebig = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if(resolve[ni][nj] == resolve[i][j]) continue;
                int from_room = resolve[i][j];
                int to_room = resolve[ni][nj];
                combinebig = max(combinebig,room[from_room]+room[to_room]);
            }
        }
    }
    cout<<combinebig<<'\n';

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<resolve[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
