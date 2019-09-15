#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> skill(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        skill[i] = temp;
    }
    sort(skill.begin(),skill.end());
    int ans = 1;
    int i = 0;
    while(i<n) {
        if(n-i < ans) break;
        int comp = 1;
        for(int j=i+1; j<n; j++) {
            if(skill[j] - skill[i] <= 5) {
                comp++;
            } else break;
        }
        ans = max(ans,comp);
        i++;
    }
    cout<<ans;
}
