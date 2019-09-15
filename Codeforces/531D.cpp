#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int main(void) {
    int len;
    cin>>len;
    string s;
    cin>>s;
    int cnt[3] = { -len/3, -len/3, -len/3};
    int sub[3];
    for(int i=0; i<len; i++) {
        cnt[s[i]-48]++;
    }
    int i=0;
    for(; i<len; i++) {
        if(cnt[0] < 0) {    //1,2 -> 0;
            if(s[i] == '0' || cnt[s[i]-48] <= 0) continue;
            cnt[s[i]-48]--;
            cnt[0]++;
            s[i] = '0';
        } else if(cnt[1] < 0){  //2 -> 1
            if(s[i] != '2' || cnt[s[i]-48] <= 0) continue;
            cnt[2]--;
            cnt[1]++;
            s[i] = '1';
        }
    }
    for(i = len -1; i>=0; --i) { //0,1 -> 2
        if(cnt[2] < 0) {
            if(s[i] == '2' || cnt[s[i]-48] <= 0) continue;
            cnt[s[i]-48]--;
            cnt[2]++;
            s[i] = '2';
        } else if(cnt[1] < 0) {  // 0 -> 1
            if(s[i] == 0 || cnt[s[i]-48] <= 0) continue;
            cnt[0]--;
            cnt[1]++;
            s[i] = '1';
        }
    }
    cout<<s;
}

