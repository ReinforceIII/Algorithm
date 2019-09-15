#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> adjlist(n+1);
    for(int i=0; i<edge.size(); i++) {
        int from = edge[i][0];
        int to = edge[i][1];
        adjlist[from].emplace_back(to);
        adjlist[to].emplace_back(from);
    }
    vector<bool> visited(n+1);
    vector<int> node_len(n+1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    node_len[1] = 1;
    int maxi = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        maxi = max(maxi,node_len[now]);
        for(int i=0; i<adjlist[now].size(); i++) {
            if(visited[adjlist[now][i]] == false) {
                q.push(adjlist[now][i]);
                visited[adjlist[now][i]] = true;
                node_len[adjlist[now][i]] = node_len[now] + 1;
            }
        }
    }
    int answer = 0;
    for(int i=0; i<node_len.size(); i++) {
        if(node_len[i] == maxi) answer++;
    }
    return answer;
}