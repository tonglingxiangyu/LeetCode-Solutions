#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        if(n == 1) return nums[0];
        int Sum = 0;
        for(int i = 0; i < n; i++){
            Sum += nums[i];
            ans = max(ans, Sum);
            if(Sum < 0){
                Sum = 0;
            }
        }
        return ans;
    }
};