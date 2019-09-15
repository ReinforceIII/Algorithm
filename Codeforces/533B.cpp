#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    string s_map = s;
    sort(s_map.begin(),s_map.end());
    auto it = unique(s_map.begin(),s_map.end());
    s_map.resize(distance(s_map.begin(),it));

    int level = -1;
    for(int i=0; i<s_map.size(); i++) {
        char selected = s_map[i];
        int conti = 0;
        int curr_level = 0;
        for(int si = 0; si<s.length(); si++) {
            if(s[si] == selected) conti++;
            else conti = 0;

            if(conti == k) {
                curr_level++;
                conti = 0;
            }
        }
        if(level < curr_level) level = curr_level;
    }
    cout<<level;
}

