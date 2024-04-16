class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int n = nums.length;
        if(n == 1) return nums[0];
        int Sum = 0;
        for(int i = 0; i < n; i++){
            Sum += nums[i];
            ans = Math.max(ans, Sum);
            if(Sum < 0) Sum = 0;
        }
        return ans;
    }
}