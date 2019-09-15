#include <string>
#include <vector>

using namespace std;
vector<vector<int>> result;
void hanoi(int n, int from, int to, int waypoint) {
    if(n==1) {
        vector<int> put = {from,to};
        result.emplace_back(put);
        return;
    }
    hanoi(n-1,from,waypoint,to);
    vector<int> put = {from,to};
    result.emplace_back(put);
    hanoi(n-1,waypoint,to,from);    
}

vector<vector<int>> solution(int n) {
    hanoi(n,1,3,2);
    return result;
}