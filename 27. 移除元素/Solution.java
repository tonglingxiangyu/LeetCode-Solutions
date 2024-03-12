class Main {
    public static void main(String[] args) {
        solution solution = new solution();
        
        // 测试用例1: 目标值在数组中
        int[] nums1 = {-1,0,3,5,9,12};
        int target1 = 9;
        System.out.println("index = " + solution.search(nums1, target1));
    }
}

class Solution {
    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        int slow = 0, fast = 0;
        while(fast < n){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;

    }
}