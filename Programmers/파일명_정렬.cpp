#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <tuple>

using namespace std;

pair<string,int> tokenize(string s) {
    string result1;
    int result2;
    
    string temp = "";
    int process = 0;
    while(true) {
        s[process] = tolower(s[process]);
        if((s[process] >= 'a' && s[process] <= 'z') ||
           s[process] == ' ' || s[process] == '.' ||
           s[process] == '-') temp += s[process++];
        else break;
    }
    for(int i=0; i<temp.length(); i++) temp[i] = tolower(temp[i]);
    result1 = temp;
    temp = "";
    int len = 1;
    while(process < s.length() && len <= 5) {
        if(s[process] >= '0' && s[process] <= '9') {
            temp += s[process++];
            len++;
        } else break;
    }
    result2 = atoi(temp.c_str());
    
    return make_pair(result1,result2);
}

bool comp(const string& lhs, const string& rhs) {
    string lhs_head, rhs_head;
    int lhs_number, rhs_number;
    tie(lhs_head,lhs_number) = tokenize(lhs);
    tie(rhs_head,rhs_number) = tokenize(rhs);
    
    if(lhs_head == rhs_head) return lhs_number < rhs_number;
    else return lhs_head < rhs_head;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(),comp);
    return files;
}