#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> gifts(k);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        gifts[temp%k]++;
    }
    int ans = 0;
    ans += gifts[0]/2;
    if(k%2 == 0) ans += gifts[k/2]/2;
    for(int i=1; i<(k+1)/2; i++) {
        ans += min(gifts[i],gifts[k-i]);
    }

    cout<<ans*2;
}
