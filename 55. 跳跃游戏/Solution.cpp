#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= cover; i++){
            cover = max(cover, nums[i]+i);
            if(cover >= nums.size()-1) return true;
        }
        return false;
    }
};

