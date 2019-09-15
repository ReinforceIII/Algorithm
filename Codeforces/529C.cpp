#include <bits/stdc++.h>
#define MAX 31 //2^29 < 10^9 < 2^30
using namespace std;

int main() {
    long long n;
    int k;
    cin>>n>>k;
    if(n < k) {
        cout<<"NO";
        return 0;
    }
    //create Binary Map
    int count = 0;
    vector<long long> result(MAX,0);
    int highest_index = 0;
    for(int i = 0; pow(2,i)<=n; i++) {
        if(n & (1 << i)) {
            result[i] = 1;
            count++;
            highest_index = max(highest_index,i);
        }
        if(count > k) {
            cout<<"NO";
            return 0;
        }
    }
    //Make List
    while(1) {
        if(count == k) {
            cout<<"YES"<<endl;
            for(int r = 0; r<MAX; r++) {
                for(int i=0; i<result[r]; i++) {
                    long long res = pow(2,r);
                    cout<<res<<" ";
                }
            }
            break;
        }
        result[highest_index]--;
        result[highest_index-1]+=2;
        count++;
        if(result[highest_index] == 0) highest_index--;
    }
    return 0;
}
