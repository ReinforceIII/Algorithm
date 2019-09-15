#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> damage;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        damage.push_back(temp);
    }
    string command;
    cin>>command;
    command += '-';
    vector<int> sameCmd;
    auto result = 0LL;
    for(int i=1; i<=n; i++) {
        if(command[i] == command[i-1]) sameCmd.push_back(damage[i-1]);
        else {
            sameCmd.push_back(damage[i-1]);
            sort(sameCmd.begin(),sameCmd.end(),greater<int>());
            for(auto d=0; d<k && d<sameCmd.size(); d++) {
                result += sameCmd[d];
            }
            sameCmd.clear();
        }
    }
    cout<<result;
}
