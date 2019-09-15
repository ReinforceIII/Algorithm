#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin>>s;
    stack<char> stk;
    int len = s.length();
    int removed = 0;
    for(int i=0; i<len; i++){
        if(!stk.empty() && stk.top() == s[i]) {
            stk.pop();
            removed++;
        } else {
            stk.push(s[i]);
        }
    }

    if(removed % 2 == 1) cout<<"Yes";
    else cout<<"No";

}

