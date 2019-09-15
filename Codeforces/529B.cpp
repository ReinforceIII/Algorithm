#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int result = min((a[n-2] - a[0]),(a[n-1] - a[1]));
    cout<<result<<endl;

    return 0;
}
