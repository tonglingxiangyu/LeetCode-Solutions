class Solution {
public:
    int countWays(vector<int>& nums) {
        /*
            我们可以先将 nums 排序
            1.如果我们一个都不选，只要 nums 最小的值大于 0 即可
            2.如果选择 i+1 个人，那么只要 num[i] < i+1 < nums[i+1] 即可，如果 i = n-1，只要nums的最大值小于 n 即可。
        */
        sort(nums.begin(), nums.end()); // 这个排序的时间复杂度 O(nlogn)，主要时间开销在这里
        int n = nums.size();
        int ans = nums[0] > 0; // 如果我们一个都不选，只要 nums 最小的值大于 0 即可
        for(int i = 0; i < n - 1; i++){
            if(nums[i] < i + 1 && i + 1 < nums[i + 1]){
                ans++;
            }
        }
        return ans + 1; // 如果 i = n-1，只要nums的最大值小于 n 即可，题意可知满足 nums[i] < n 条件
    }
};