#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,x,y;
    cin>>n>>x>>y;

    if(x > y) cout<<n;
    else {
        int lower = 0;
        for(int i=0; i< n; i++) {
            int temp;
            cin>>temp;
            if(temp <= x) lower++;
        }
        if(lower%2 == 1) cout<<(lower/2)+1;
        else cout<<lower/2;
    }
    return 0;
}

