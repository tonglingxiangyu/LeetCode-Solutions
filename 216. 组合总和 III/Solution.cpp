#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        backtrack(1, 0, 0, combination, k, n, res);

        return res;
    }

    void backtrack(int number, int nums, int sum, vector<int>& combination, int& k, int& n, vector<vector<int>>& res){
        if(nums == k && sum == n){
            res.push_back(combination);
            return;
        }
        if(sum > n) return;
        for(int i = number; i <= 9; i++){
            sum += i;
            combination.push_back(i);
            backtrack(i+1, nums+1, sum, combination, k, n, res);
            sum -= i;
            combination.pop_back();
        }
    }
};