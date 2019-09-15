#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int,int> num_play;

bool comp1(const pair<string,int>& lhs, const pair<string,int>& rhs) {
    return lhs.second > rhs.second;
}

bool comp2(const num_play& lhs, const num_play& rhs) {
    return lhs.second > rhs.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    map<string,vector<num_play>> music;
    map<string,int> total;
    for(int i=0; i<n; i++) {
        int num = i;
        string g = genres[i];
        int p = plays[i];
        music[g].emplace_back(num,p);
        total[g] += plays[i];
    }
    vector<pair<string,int>> tv;
    for(auto iter = total.begin(); iter != total.end(); iter++) {
        tv.emplace_back(iter->first,iter->second);
    }
    sort(tv.begin(),tv.end(),comp1);
    for(int i=0; i<tv.size(); i++) {
        string now_s = tv[i].first;
        vector<num_play> now_v = music.find(now_s)->second;
        sort(now_v.begin(),now_v.end(),comp2);
        for(int j=0; j<now_v.size(); j++) {
            if(j == 2) break;
            answer.emplace_back(now_v[j].first);
        }
    }
    return answer;
}