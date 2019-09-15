#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    
    int maxlim = routes[0][1];
    for(int i=0; i<routes.size()-1; i++) {
        //카메라 가능 범위 좁히기(이번 차가 갈 수 있는 최대랑 비교)
        if(maxlim > routes[i][1]) maxlim = routes[i][1];
        //그 다음 차가 이 범위 끝보다 앞에서 출발한다면 카메라 새로설치
        if(maxlim < routes[i+1][0]) {
            answer++;
            maxlim = routes[i+1][1];
        }
    }
    
    return answer;
}