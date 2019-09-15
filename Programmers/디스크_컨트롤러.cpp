#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int time = jobs[0][0];
    int ndisk = 1;
    pq.emplace(jobs[0][1],jobs[0][0]);
    while(!pq.empty() || ndisk < jobs.size()) {
        if(pq.empty()) time++;
        else {
            int sche = pq.top().first;
            int start = pq.top().second; pq.pop();
            time += sche;
            answer += (time - start);
        }
        while(true) {
            if(ndisk < jobs.size() && jobs[ndisk][0] <= time) {
                pq.emplace(jobs[ndisk][1],jobs[ndisk][0]);
                ndisk++;
            } else break;
        }
    }
    return answer/jobs.size();
}