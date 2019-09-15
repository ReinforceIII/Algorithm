#include <bits/stdc++.h>

using namespace std;

int main() {
    int w,h;
    cin>>w>>h;
    int sw1,sh1,sw2,sh2;
    cin>>sw1>>sh1;
    cin>>sw2>>sh2;
    do {
        w += h;
        if(h == sh1) w -= sw1;
        if(h == sh2) w -= sw2;

        if(w < 0) w = 0;
    } while(h--);

    cout<<w<<endl;
    return 0;
}
