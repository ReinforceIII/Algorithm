#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<set<int>> adjwin(n+1);
    vector<set<int>> adjlose(n+1);
    for(int i=0; i<results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        adjwin[win].insert(lose);
        adjlose[lose].insert(win);
    }
    for(int t = 0; t < 2; t++) {
        for(int i=1; i<=n; i++) {
            //win table
            for(auto j = adjwin[i].begin(); j != adjwin[i].end(); j++) {
                int llose = *j;
                adjwin[i].insert(adjwin[llose].begin(),adjwin[llose].end());
            }
            //lose table
            for(auto j = adjlose[i].begin(); j != adjlose[i].end(); j++) {
                int wwin = *j;
                adjlose[i].insert(adjlose[wwin].begin(),adjlose[wwin].end());
            }
        }
    }
    int answer = 0;
    for(int i=1; i<=n; i++) {
        if(adjwin[i].size() + adjlose[i].size() >= n-1) answer++;
    }
    return answer;
}