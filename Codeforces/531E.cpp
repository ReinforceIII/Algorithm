#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int main(void) {
    int len;
    cin>>len;

    vector<int> arr;
    for(int i=0; i<len; i++) {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    map<int,int> n_high;
    for(int i=0; i<arr.size(); i++) {
        n_high[arr[i]] = i;
    }
    long long result = 1;
    int high_block = n_high[arr[0]];
    for(int i=1; i<len; i++) {
        if(i <= high_block) {
            high_block = max(high_block, n_high[arr[i]]);
            continue;
        }

        high_block = n_high[arr[i]];
        result = result * 2 % MOD;
    }

    cout<<result;
}

