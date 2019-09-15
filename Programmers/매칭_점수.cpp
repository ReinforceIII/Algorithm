#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> adjlist;

string get_link(string word){
    string address = "<meta property=\"og:url\" content=\"";
    int start = word.find(address);
    int ed = word.find("\"",start+address.size());
    return string(word.begin()+start+address.size(),word.begin()+ed);
}

int get_word_cnt(string word, string entire){
    int result = 0;
    entire.push_back('!');
    string temp = "";
    for(int i=0; i<entire.size(); i++) {
        entire[i] = tolower(entire[i]);
        if(entire[i] >= 'a' && entire[i] <= 'z') temp+=entire[i];
        else {
            if(temp == word) result++;
            temp = "";
        }
    }
    return result;
}

bool comp(const pair<int,double>& lhs, const pair<int,double>& rhs) {
    if(lhs.second == rhs.second) return lhs.first < rhs.first;
    return lhs.second > rhs.second;
}

int solution(string word, vector<string> pages) {
    map <string,int> link_list;
    vector<int> basepoint(pages.size(),0);
    vector<int> linkconnect(pages.size(),0);
    vector<double> linkpoint(pages.size(),0);
    adjlist = vector<vector<int>>(pages.size());
    for(int i=0; i<pages.size(); i++) {
        for(int k=0; k<word.size(); k++) word[k] = tolower(word[k]);
        string myaddr = get_link(pages[i]);
        link_list[myaddr] = i;
        basepoint[i] = get_word_cnt(word,pages[i]);
    }
    for(int i=0; i<pages.size(); i++) {
        string bstart = "<a href=\"";
        int curr = 0;
        while(true) {
            int start = pages[i].find(bstart,curr);
            if(start == string::npos) break;
            int ed = pages[i].find("\"",start+bstart.size());
            string link = string(pages[i].begin()+start+bstart.size(),pages[i].begin()+ed);
            linkconnect[i]++;
            if(link_list.count(link) > 0) adjlist[link_list[link]].push_back(i);
            curr = ed;
        }
    }
    for(int i=0; i<pages.size(); i++) {
        linkpoint[i] += basepoint[i];
        for(auto& fromto : adjlist[i]) {
            linkpoint[i] += (double)basepoint[fromto]/linkconnect[fromto];
        }
    }
    vector<pair<int,double>> ans;
    for(int i=0; i<pages.size(); i++) {
        ans.emplace_back(i,linkpoint[i]);
    }
    sort(ans.begin(),ans.end(),comp);
    return ans[0].first;
}