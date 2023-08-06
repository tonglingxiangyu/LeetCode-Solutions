#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int a = purchaseAmount % 10;
        int ans;
        if(a < 5){
            ans = purchaseAmount - a;
        }
        else{
            ans = purchaseAmount - a + 10;
        }
        return 100 - ans;
    }
};



