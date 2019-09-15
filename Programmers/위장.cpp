#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int n = clothes.size();
    map<string,int> com;
    for(auto c = clothes.begin(); c!= clothes.end(); c++) {
        vector<string> t = *c;
        com[t[1]] += 1;
    }
    int answer = 1;
    for(auto m = com.begin(); m != com.end(); m++) {
        int s = m->second + 1;
        answer *= s;
    }
	return answer-1;
}