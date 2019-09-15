#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;

    vector<long long> a;
    for(int i=0; i<n; i++) {
        long long temp;
        cin>>temp;
        a.push_back(temp);
    }
    vector<long long> sa = a;
    sort(sa.rbegin(),sa.rend());
    int beauty_count = m*k;
    long long result = accumulate(sa.begin(),sa.begin()+beauty_count,0LL);
    cout<<result<<"\n";

    multiset<long long> answerSet(sa.begin(),sa.begin()+beauty_count);
    int split = 1;
    int i = 0;
    while(split < k) {
        int comp = 0;
        while(1) {
            auto iter = answerSet.find(a[i++]);
            if(iter != answerSet.end()) {
                comp++;
                answerSet.erase(iter);
            }

            if(comp == m) {
                split++;
                cout<<i<<" ";
                break;
            }
        }
    }
}
