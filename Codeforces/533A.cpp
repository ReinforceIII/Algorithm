#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin>>n;
    vector<int> number;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        number.push_back(temp);
    }

    sort(number.begin(),number.end());
    int min_limit = number[0];
    int max_limit = number[n-1];
    int result_t = min_limit;
    int cost = 9999999;
    for(int t = min_limit; t<=max_limit; t++) {
        int temp_cost = 0;
        for(int elem : number) {
            if(abs(elem-t) > 1) {
                temp_cost += min(abs(elem-t-1),abs(elem-t+1));
            }
        }
        if(temp_cost < cost) {
            result_t = t;
            cost = temp_cost;
        }
    }
    cout<<result_t<<" "<<cost;
}

