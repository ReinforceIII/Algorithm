#include <string>
#include <vector>

using namespace std;
bool visited[200];
vector<vector<int>> pro_map;
int N;
void dfs(int start) {
    visited[start] = true;
    for(int i=0; i<N; i++) {
        if(visited[i] == false && pro_map[start][i] == 1) {
            dfs(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    pro_map = computers;
    N = n;
    for(int i=0; i<N; i++) {
            if(visited[i] == false) {
                answer++;
                dfs(i);
            }
    }
    return answer;
}