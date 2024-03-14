class Main {
    public static void main(String[] args) {
        solution solution = new solution();
        
        // 测试用例1: 目标值在数组中
        int[] nums1 = {-1,0,3,5,9,12};
        System.out.println("ans = " + solution.sortedSquares(nums1));
    }
}

class Solution {
    // 滑动窗口
    public int minSubArrayLen(int s, int[] nums) {
        int left = 0;
        int sum = 0;
        int result = Integer.MAX_VALUE;
        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];
            while (sum >= s) {
                result = Math.min(result, right - left + 1);
                sum -= nums[left++];
            }
        }
        return result == Integer.MAX_VALUE ? 0 : result; // 如果result等于Integer.MAX_VALUE返回0，否则返回result
    }
}
