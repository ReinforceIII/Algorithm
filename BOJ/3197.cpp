/* 3197 백조의 호수 */
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
bool w_visited[1500][1500];
bool s_visited[1500][1500];
int n,m;

int main(void) {
    cin>>n>>m;
    vector<string> pro_map(n);
    for(int i=0; i<n; i++) {
        cin>>pro_map[i];
    }
    loca swan[2];   //swan 0 from swan 1 to
    queue<loca> wq,nwq,sq,nsq;
    int s_temp = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(pro_map[i][j] == 'L') {
                swan[s_temp++] = make_pair(i,j);
                pro_map[i][j] = '.';
            }
            if(pro_map[i][j] == '.') {
                wq.emplace(i,j);
                w_visited[i][j] = true;
            }
        }
    }
    sq.emplace(swan[0].first,swan[0].second);
    s_visited[swan[0].first][swan[0].second] = true;

    int day = 0;
    while(true) {
        //1. water 처리 & melt
        while(!wq.empty()) {
            int wx = wq.front().first;
            int wy = wq.front().second;
            wq.pop();
            pro_map[wx][wy] = '.';
            for(int k=0; k<4; k++) {
                int nx = wx + dx[k];
                int ny = wy + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(w_visited[nx][ny]) continue;
                if(pro_map[nx][ny] == '.') {
                    wq.emplace(nx,ny);
                    w_visited[nx][ny] = true;
                } else {
                    nwq.emplace(nx,ny);
                    w_visited[nx][ny] = true;
                }
            }
        }
        //2. 백조 bfs
        while(!sq.empty()) {
            int sx = sq.front().first;
            int sy = sq.front().second;
            sq.pop();
            for(int k=0; k<4; k++) {
                int nx = sx + dx[k];
                int ny = sy + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(s_visited[nx][ny]) continue;
                if(pro_map[nx][ny] == '.') {
                    sq.emplace(nx,ny);
                    s_visited[nx][ny] = true;
                } else {
                    nsq.emplace(nx,ny);
                    s_visited[nx][ny] = true;
                }

            }
        }
        if(s_visited[swan[1].first][swan[1].second]) {
            cout<<day;
            break;
        }

        wq = nwq; sq = nsq;
        nwq = queue<loca>();
        nsq = queue<loca>();
        day++;
    }
    
    return 0;
}
