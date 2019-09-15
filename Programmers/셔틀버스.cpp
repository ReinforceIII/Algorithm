#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<timetable.size(); i++) {
        string hs = timetable[i].substr(0,2);
        string ms = timetable[i].substr(3,2);
        int hour = atoi(hs.c_str());
        int minute = atoi(ms.c_str());
        pq.push(hour*60+minute);
    }
    int cnt = 0;
    int leave = 9*60; //09:00 첫차
    for(int i=0; i<n-1; i++) {
        leave = 9*60 + i*t;
        cnt = 0;
        while(!pq.empty() && cnt < m) {
            if(pq.top() <= leave) {
                pq.pop();
                cnt++;
            } else break;
        }
    }
    
    leave = 9*60 + (n-1)*t;
    cnt = 0;
    while(!pq.empty() && cnt < m-1) {
        if(pq.top() <= leave) {
            pq.pop();
            cnt++;
        } else break;
    }
    int result;
    if(pq.empty() || pq.top() > leave) result = leave;
    else result = pq.top() - 1;
    
    int hour = result/60;
    int minute = result%60;
    
    answer += (hour/10) + '0';
    answer += (hour%10) + '0';
    answer += ":";
    answer += (minute/10) + '0';
    answer += (minute%10) + '0';
    
    return answer;
}