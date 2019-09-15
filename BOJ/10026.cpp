/* 10026 적록색약 */
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
int n; 

bool recog(char from, char to, bool blind) {
    if(from == to) return true;
    if(blind) {
        if(from == 'R' && to == 'G') return true;
        if(from == 'G' && to == 'R') return true;
    }
    return false;
}

int bfs(vector<string>& pro_map, bool blind) {
    int result = 0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<loca> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(visited[i][j] == false) {
                result++;
                q.emplace(i,j);
                visited[i][j] = true;
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(visited[nx][ny] == true) continue;
                        if(recog(pro_map[x][y],pro_map[nx][ny],blind)) {
                            visited[nx][ny] = true;
                            q.emplace(nx,ny);
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main(void) {
    cin>>n;
    vector<string> pro_map(n);
    for(int i=0; i<n; i++) {
        cin>>pro_map[i];
    }
    cout<<bfs(pro_map,false)<<" "<<bfs(pro_map,true);
    return 0;
}
