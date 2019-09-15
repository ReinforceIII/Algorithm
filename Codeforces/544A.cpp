#include <bits/stdc++.h>
using namespace std;

int main() {
    string from,to;
    cin>>from;
    cin>>to;
    int from_h,from_m;
    int to_h, to_m;
    from_h = stoi(from.substr(0,2));
    from_m = stoi(from.substr(3));
    to_h = stoi(to.substr(0,2));
    to_m = stoi(to.substr(3));
    int from60 = from_h*60 + from_m;
    int to60 = to_h*60 + to_m;
    int middle60 = (from60+to60)/2;
    printf("%02d:%02d\n",middle60/60,middle60%60);
}
