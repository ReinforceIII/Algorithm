#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    for(int i=0; i<cities.size(); i++) {
        string now = cities[i];
        for(int k=0; k<now.length(); k++) now[k] = tolower(now[k]);
        if(find(cache.begin(),cache.end(),now) == cache.end()) {
            //cache miss
            if(cache.size() == cacheSize) {
                if (cacheSize > 0) cache.pop_front();
            }
            if(cache.size() < cacheSize) cache.push_back(now);
            answer+=5;
        } else {
            //cache hit
            cache.remove(now);
            cache.push_back(now);
            answer+=1;
        }
    }
    return answer;
}