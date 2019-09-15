#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> broken;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        broken.push_back(temp);
    }

    vector<int> tapeLen;
    adjacent_difference(broken.begin(),broken.end(),back_inserter(tapeLen));
    tapeLen.erase(tapeLen.begin());
    sort(tapeLen.begin(),tapeLen.end());
    cout<<accumulate(tapeLen.begin(),tapeLen.end()-k+1,0) + k;
}


/*
adjacent_difference
y0 = x0
y1 = x1 - x0
y2 = x2 - x1
y3 = x3 - x2
y4 = x4 - x3
...
*/
