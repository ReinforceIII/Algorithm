#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    string result = "";
    int times = 0;
    for(int i=0; i<n; i+=times) {
        result+=s[i];
        times++;
    }
    cout<<result<<endl;
    return 0;
}
