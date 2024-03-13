class Main {
    public static void main(String[] args) {
        solution solution = new solution();
        
        // 测试用例1: 目标值在数组中
        int[] nums1 = {-1,0,3,5,9,12};
        System.out.println("ans = " + solution.sortedSquares(nums1));
    }
}

class Solution {
    public int[] sortedSquares(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            nums[i] = nums[i] * nums[i];
        }
        Arrays.sort(nums);
        return nums;
    }
}