/* 12886번 돌 그룹 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;
bool visited[1501][1501];
typedef pair<int,int> group;
int main(void) {
    int one,two,three;
    cin>>one>>two>>three;
    int total = one+two+three;
    group g = make_pair(one,two);
    queue<group> q;
    q.emplace(g);
    visited[one][two] = 1;
    while(!q.empty()) {
        int n_one,n_two,n_three;
        tie(n_one,n_two) = q.front(); q.pop();
        n_three = total-n_one-n_two;
        if(n_one == n_two && n_two == n_three) {
            cout<<1;
            return 0;
        }
        
        if(n_one != n_two) {
            if(n_one < n_two && visited[n_one+n_one][n_two-n_one] == false) {
                q.emplace(n_one+n_one,n_two-n_one);
                visited[n_one+n_one][n_two-n_one] = true;
            } else if(n_one > n_two && visited[n_one-n_two][n_two+n_two] == false) {
                q.emplace(n_one-n_two,n_two+n_two);
                visited[n_one-n_two][n_two+n_two] = true;
            }
        } 
        if(n_one != n_three) {
            if(n_one < n_three && visited[n_one+n_one][n_two] == false) {
                q.emplace(n_one+n_one,n_two);
                visited[n_one+n_one][n_two] = true;
            } else if(n_one > n_three && visited[n_one-n_three][n_two] == false) {
                q.emplace(n_one-n_three,n_two);
                visited[n_one-n_three][n_two] = true;
            }
        }
        if(n_two != n_three) {
            if(n_two < n_three && visited[n_one][n_two+n_two] == false) {
                q.emplace(n_one,n_two+n_two);
                visited[n_one][n_two+n_two] = true;
            } else if(n_two > n_three && visited[n_one][n_two-n_three] == false) {
                q.emplace(n_one,n_two-n_three);
                visited[n_one][n_two-n_three] = true;
            }
        }
    }
    cout<<0;
    return 0;
}
