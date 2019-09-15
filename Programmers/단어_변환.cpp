#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int resolve[50];
bool can(string s1, string s2) {
    int diff = 0;
    for(int i=0; i<s1.size(); i++) {
        if(s1[i] != s2[i]) diff++;
    }
    if(diff == 1) return true;
    else return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool pre_chk = false;
    int tidx;
    for(int i=0; i<words.size(); i++) {
        if(target == words[i]) {
            pre_chk = true;
            tidx = i;
            break;
        }
    }
    if(pre_chk == false) return 0;
    
    queue<int> q;
    int nowidx;
    string now = begin;
    q.push(-1);
    while(!q.empty()) {
        if(q.front() != -1) {
            nowidx = q.front();
            now = words[nowidx];
        }
        q.pop();
        for(int i=0; i<words.size(); i++) {
            if(resolve[i] != 0) continue;
            if(can(now,words[i])) {
                q.push(i);
                resolve[i] = resolve[nowidx] + 1;
            }
        }
    }
    return resolve[tidx];
}