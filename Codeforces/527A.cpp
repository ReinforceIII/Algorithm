#include <bits/stdc++.h>

using namespace std;

int main() {
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin>>t;
    for(int l=0; l<t; l++) {
        string answer = "";
        int n,k;
        cin>>n>>k;
        int div = n/k;
        int rest = n%k;
        for(int i=0; i<k; i++) {
            for(int d =0; d<div; d++) {
                answer += alpha[i];
            }
        }
        for(int r=0; r<rest; r++) {
            answer += alpha[r];
        }
        cout<<answer<<"\n";
    }

    return 0;
}
