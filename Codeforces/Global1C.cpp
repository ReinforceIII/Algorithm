#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b);
int main() {
    int q;
    cin>>q;
    while(q--) {
        long long a;
        cin>>a;
        int count = 0;
        int i = 0;
        for(; pow(2,i)<=a; i++) {
            if(a & (1 << i)) count++;
        }
        if(i == count) {
            long long divisor = 1;
            for(int i=2; i*i <= a; i++) {
                if(a%i == 0) {
                    divisor = max(divisor,a/i);
                    break;
                }
            }
            cout<<gcd(a,divisor)<<endl;
        } else {
            cout<<(long long)pow(2,i)-1<<endl;
        }
    }

}

long long gcd(long long a, long long b) {
    return (b==0) ? a: gcd(b, a%b);
}
