#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
    for(int i=0; i<str1.length(); i++) str1[i] = tolower(str1[i]);
    for(int i=0; i<str2.length(); i++) str2[i] = tolower(str2[i]);
    
    int answer = 0;
    multiset<string> ones, twos;
    for(int i=0; i<str1.length()-1; i++) {
        string temp = "";
        if(str1[i] < 'a' || str1[i] > 'z' || str1[i+1] < 'a' || str1[i+1] > 'z') continue;
        temp = str1.substr(i,2);
        ones.insert(temp);
    }
    for(int i=0; i<str2.length()-1; i++) {
        string temp = "";
        if(str2[i] < 'a' || str2[i] > 'z' || str2[i+1] < 'a' || str2[i+1] > 'z') continue;
        temp = str2.substr(i,2);
        twos.insert(temp);
    }
    vector<string> uni(str1.length()+str2.length());
    vector<string> inter(str1.length()+str2.length());
    set_union(ones.begin(),ones.end(),twos.begin(),twos.end(),uni.begin());
    set_intersection(ones.begin(),ones.end(),twos.begin(),twos.end(),inter.begin());
    
    uni.erase(find(uni.begin(),uni.end(),""),uni.end());
    inter.erase(find(inter.begin(),inter.end(),""),inter.end());
    
    if(ones.size() == 0 && twos.size() == 0) answer = 65536;
    else {
        double temp = (double)inter.size()/uni.size();
        answer = (int)(65536*temp);
    }
    return answer;
}