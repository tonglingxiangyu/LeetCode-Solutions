#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string N = to_string(n);
        int flag = N.size();
        for(int i = N.size()-1; i > 0; i--){
            if(N[i-1] > N[i]){
                flag = i;
                N[i-1]--;
            }
        }
        for(int i = flag; i < N.size(); i++){
            N[i] = '9';
        }
        return stoi(N);
    }
};