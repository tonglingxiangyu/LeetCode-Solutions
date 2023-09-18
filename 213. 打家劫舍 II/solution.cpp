class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            考虑是否偷 nums[0]，那么可以分为两种情况：
            1.如果偷 nums[0]]，那么 nums[1] 和 nums[n−1] 不能偷，问题变成从 nums[2] 到 nums[n−2] 的非环形版本。这里官方题解计算的是 nums[0] 到 nums[n−2]，感觉绕了一个弯，不如直接求 nums[2] 到 nums[n−2]。
            2.如果不偷 nums[0]，那么问题变成从 nums[1] 到 nums[n−1] 的非环形版本。

            这两种方案覆盖了所有情况（毕竟 nums[0] 只有偷与不偷，没有第三种选择），所以取两种方案的最大值，即为答案。
        */
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        // 偷nums[0]的情况
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n - 2; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int max1 = dp[n - 2] + nums[0];

        // 不偷nums[0]的情况
        
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for(int i = 3; i <= n - 1; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int max2 = dp[n - 1];
        return max(max1, max2);
    }
};