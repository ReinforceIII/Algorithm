#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> pos;
char map[31][31];
int sqdx[4] = {0,1,0,1};
int sqdy[4] = {0,0,1,1};

bool rec_check(int x,int y, int m, int n);
void recover(int m, int n);

int solution(int m, int n, vector<string> board) {
    set<pos> del;
    int answer = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            map[i][j] = board[i][j];
        }
    }
    bool found = false;
    while(true) {
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++) {
                if(map[i][j] != '-' &&rec_check(i,j,m,n)) {
                    found = true;
                    for(int k=0; k<4; k++) del.emplace(i+sqdx[k],j+sqdy[k]);                
                }
            }
        }
        if(found == false) break;
        answer += del.size();
        for(auto iter = del.begin(); iter != del.end(); iter++) {
            int x = iter->first;
            int y = iter->second;
            map[x][y] = '-';
        }
        del.clear();
        recover(m,n);
        found = false;
    }
    
    return answer;
}

bool rec_check(int x,int y, int m, int n) {
    char origin = map[x][y];
    if(x+1 < m && y+1 < n) {
        if(map[x+1][y] == origin && map[x][y+1] == origin && map[x+1][y+1] == origin) {
            return true;
        }
    }
    return false;
}
void recover(int m, int n) {
    //find bottom black
    for(int j=0; j<n; j++) {
        int bottom = -1;
        vector<int> remain;
        for(int i=m-1; i>=0; i--) {
            if(map[i][j] == '-') {
                bottom = i;
                break;
            }
        }
        if(bottom == -1) continue; //no blank -> need not recover.
        //find remain block.
        for(int i=bottom; i>=0; i--) {
            if(map[i][j] != '-') remain.push_back(i);
        }
        if(remain.size() == 0) continue; //no remain block. -> need not recover.
        for(auto iter = remain.begin(); iter != remain.end(); iter++) {
            int now = *iter;
            map[bottom][j] = map[now][j];
            map[now][j] = '-';
            bottom--;
        }
    }
}