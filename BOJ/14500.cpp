/* 14500 테트로미노 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <limits.h>
#include <cstring>
using namespace std;

typedef pair<int,int> loca;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int pro_map[500][500];
bool visited[500][500];
int n,m;
int answer = 0;

void recur(int x, int y, int sum, int count) {
    if(count == 4) {
        answer = max(answer,sum);
        return;
    }
    if(x < 0 || x >=n || y < 0 || y >= m) return;
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int k=0; k<4; k++) {
        recur(x+dx[k],y+dy[k],sum+pro_map[x][y],count+1);
    }
    visited[x][y] = false;
}

int main(void) {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>pro_map[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            recur(i,j,0,0);
            if(j+2 < m) {
                int temp_sum = pro_map[i][j] + pro_map[i][j+1] + pro_map[i][j+2];
                if(i-1 >= 0) {
                    int t_sum = temp_sum + pro_map[i-1][j+1];
                    answer = max(answer,t_sum);
                }
                if(i+1 < n) {
                    int t_sum = temp_sum + pro_map[i+1][j+1];
                    answer = max(answer,t_sum);
                }
            }
            if(i+2 < n) {
                int temp_sum = pro_map[i][j] + pro_map[i+1][j] + pro_map[i+2][j];
                if(j-1 >= 0) {
                    int t_sum = temp_sum + pro_map[i+1][j-1];
                    answer = max(answer,t_sum);
                }
                if(j+1 < m) {
                    int t_sum = temp_sum + pro_map[i+1][j+1];
                    answer = max(answer,t_sum);
                }
            }
        }
    }
    cout<<answer;
    return 0;
}
