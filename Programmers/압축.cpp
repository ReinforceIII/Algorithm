#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> dic;
vector<int> solution(string msg) {
    vector<int> answer;
    
    //create basic dictionary
    char now = 'A';
    for(int i=1; i<=26; i++) {
        string s = "";
        s += now;
        dic[s] = i;
        now++;
    }
    int process = 0;
    int dic_next = 27;
    while(process < msg.size()) {
        int len= 1;
        string now = "";
        int pre_index;
        while(process+len <= msg.size()) {
            now = msg.substr(process,len);
            //find in dic
            if(dic.find(now) != dic.end()) {
                pre_index = dic.find(now)->second;
                len++;
            } else break;
            
        }
        dic[now] = dic_next++;
        process += (len-1);
        answer.push_back(pre_index);
        
    }
    return answer;
}