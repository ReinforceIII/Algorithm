#include <string>
#include <vector>
#include <set>

using namespace std;

bool isSub(vector<int>& v,int n) {
    for(int i=0; i<v.size(); i++) {
        if((v[i]&n) == v[i]) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int row = relation.size();
    int col = relation[0].size();
    vector<int> answer;
    for(int i=1; i<(1<<col); i++) {
        set<string> s;
        for(int j=0; j<row; j++) {
            string temp = "";
            for(int k =0; k < col; k++) {
                if(i&(1<<k)) temp += relation[j][k];
            }
            s.insert(temp);
        }
        if(s.size() == row && isSub(answer,i)) answer.push_back(i);
    }
    return answer.size();
}