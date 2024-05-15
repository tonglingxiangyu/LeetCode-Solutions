#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return ans;
    }
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(nums.size() == path.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] != false){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

