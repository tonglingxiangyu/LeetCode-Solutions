#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i-q[0]+1 > k){
                q.pop_front();
            }
            if(i >= k -1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};