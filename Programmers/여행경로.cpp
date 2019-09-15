#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<string>>& tickets, vector<bool>& visited,
         vector<string>& temp, vector<string>& answer, string from, int cnt) {
    
    temp.emplace_back(from);
    if(cnt == tickets.size()) {
        answer = temp;
        return true;
    }
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == from && visited[i] == false) {
            visited[i] = true;
            bool can = dfs(tickets,visited,temp,answer,tickets[i][1],cnt+1);
            if(can) return true;
            visited[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer,temp;
    vector<bool> visited(tickets.size(),false);
    
    sort(tickets.begin(),tickets.end());
    dfs(tickets,visited,temp,answer,"ICN",0);
    return answer;
}