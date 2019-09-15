#include <bits/stdc++.h>
using namespace std;

void simplify(pair<int,int>& p) {
    //first = numenator // second = denominator
    if(p.first < 0) {
        p.first *= -1;
        p.second *= -1;
    } else if(p.first ==0 && p.second < 0) p.second *= -1;

    int d = __gcd(abs(p.first),abs(p.second));
    p.first /= d;
    p.second /= d;
}


int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        a[i] = temp;
    }
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        b[i] = temp;
    }
    int ans = 0;
    int bothZero = 0;
    map<pair<int,int>,int> d_map;

    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            if(b[i] == 0) bothZero++;
        } else {
            pair<int, int> p = make_pair(-b[i],a[i]);
            simplify(p);
            d_map[p]++;
            ans = max(ans,d_map[p]);
        }
    }
    cout<<ans+bothZero;
}
