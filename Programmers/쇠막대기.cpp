#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    char prev = arrangement[0];     // 패턴 파악을 위해 이전 문자 저장.
    int stick = 0;
    for(int i=1; i<arrangement.length(); i++) {
        int now = arrangement[i];
        if(prev == '(' && now == '(') {
            stick++;
            answer++;
        } else if(prev == '(' && now == ')') {
            answer += stick;
        } else if(prev == ')' && now == ')') {
            stick--;
        } else {}
        prev = now;
    }
    return answer;
}