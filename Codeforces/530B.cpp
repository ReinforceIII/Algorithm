#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin>>n;
    int times = 1;
    do {
        if(n <= times*times) {
            if( n <= times*(times-1)) {
                cout<< times + times-1 <<endl;
                break;
            }
            cout<< times*2 <<endl;
            break;
        }
    } while(times++);
    return 0;
}
