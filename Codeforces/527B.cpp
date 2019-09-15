#include <bits/stdc++.h>
#define MAX 101
using namespace std;

bool isPair[MAX] = {false, };

int main() {
    int n;
    cin>>n;
    vector<int> skills;
    for(int i=0; i<n; i++) {
        int sk;
        cin>>sk;
        skills.push_back(sk);
    }
    sort(skills.begin(),skills.end());
    int result = 0;

    int times = 0;
    while(times != n) {
        int dis = skills[times+1] - skills[times];
        result += dis;
        times+=2;
    }

    cout<<result<<endl;
    return 0;
}
