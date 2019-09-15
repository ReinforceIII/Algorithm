#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin>>s;
    bool hasZero = false;
    bool hasOne = false;

    for(int i=0; i< s.length(); i++) {
        if(s[i] == '0') {
            if(!hasZero) {
                hasZero = true;
                cout<<"1 1\n";
            } else {
                hasZero = false;
                cout<<"3 1\n";
            }
        } else {
            if(!hasOne) {
                hasOne = true;
                cout<<"4 3\n";
            } else {
                hasOne = false;
                cout<<"4 1\n";
            }
        }
    }
}

