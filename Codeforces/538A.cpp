#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y,z;
    int a,b,c;

    cin>>x>>y>>z;
    cin>>a>>b>>c;
    bool isPossible = true;
    if(x > a) isPossible = false;
    else if(x+y > a+b) isPossible = false;
    else if (x+y+z > a+b+c) isPossible = false;

    if(isPossible) cout<<"YES";
    else cout<<"NO";
}
