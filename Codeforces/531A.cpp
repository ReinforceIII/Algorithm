#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int result;
    if(n%2 == 1) {
        if((n/2)%2 == 0) result = 1;
        else result = 0;
    } else {
        if((n/2)%2 == 0) result = 0;
        else result = 1;
    }
    cout<<result;
	return 0;
}

