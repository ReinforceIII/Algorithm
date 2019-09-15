/* 3184번 양 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int,int> ani_num;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
char map[250][250];
bool visited[250][250];
int r,c;

ani_num bfs(int i, int j);

int main(void) {
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>map[i][j];
            if(map[i][j] == '#') visited[i][j] = true;
            else visited[i][j] = false;
        }
    }
    int sheep = 0;
    int wolf = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(map[i][j] != '#' && visited[i][j] == false) {
                auto r = bfs(i,j);
                if(r.first == 0) sheep += r.second;
                else wolf +=r.second;
            }
        }
    }
    cout<<sheep<<" "<<wolf;
    return 0;
}

ani_num bfs(int i, int j) {
    int s=0,w=0;
    queue<pair<int,int>> q;
    q.emplace(i,j);
    visited[i][j] = true;
    while(!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        if(map[x][y] == 'o') s++;
        else if(map[x][y] == 'v') w++;
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny] == false) {
                q.emplace(nx,ny);
                visited[nx][ny] = true;
            }
        }
    }
    if(s > w) return make_pair(0,s);
    else return make_pair(1,w);
}