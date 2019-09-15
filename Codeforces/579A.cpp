#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin>>q;
    while(q--) {
        int n; cin>>n;
        vector<int> st(n);
        for(int i=0; i<n; i++) {
            cin>>st[i];
        }
        vector<int> cresendo(n);
        vector<int> decresendo(n);
        for(int i=0; i<n; i++) {
            cresendo[i] = i+1;
            decresendo[i] = n-i;
        }
        bool found = false;
        for(int i=0; i<n; i++) {
            if(cresendo == st) {
                cout<<"YES\n";
                found = true;
                break;
            }
            else if(decresendo == st) {
                cout<<"YES\n";
                found = true;
                break;
            }
            else {
                int cre_temp = cresendo[0];
                vector<int> new_cre = vector<int>(cresendo.begin()+1,cresendo.end());
                new_cre.push_back(cre_temp);
                int decre_temp = decresendo[0];
                vector<int> new_decre = vector<int>(decresendo.begin()+1,decresendo.end());
                new_decre.push_back(decre_temp);
                cresendo = new_cre;
                decresendo = new_decre;
            }
        }
        if(found == false) {
            cout<<"NO\n";
        }
    }
    return 0;
}
