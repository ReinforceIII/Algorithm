#include <bits/stdc++.h>
using namespace std;
int main() {
    int b,k;
    cin>>b>>k;
    vector<int> radix;
    for(int i=0; i<k; i++) {
        int temp;
        cin>>temp;
        radix.push_back(temp);
    }
    bool isOdd = false;
    if(b&1) {
        if(radix[0]&1) isOdd = true;
        for(int i=1; i<k; i++) {
            if((isOdd && !(radix[i]&1)) || (!isOdd && radix[i]&1)) isOdd = true;
            else isOdd = false;
        }
    } else {
        if(radix[k-1]&1) isOdd = true;
    }
    string result;
    result = isOdd ? "odd" : "even";
    cout<<result;
}
