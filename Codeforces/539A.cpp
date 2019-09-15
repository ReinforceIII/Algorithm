#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,v;
    cin>>n>>v;

    if(n-1 <= v) {
        cout<< n-1;
        return 0;
    }
    int result = v-1;
    for(int i = 1; i<= n-v; ++i) {
        result += i;
    }
    cout<<result;
}
