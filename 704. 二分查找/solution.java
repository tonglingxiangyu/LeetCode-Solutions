class Main {
    public static void main(String[] args) {
        solution solution = new solution();
        
        // 测试用例1: 目标值在数组中
        int[] nums1 = {-1,0,3,5,9,12};
        int target1 = 9;
        System.out.println("index = " + solution.search(nums1, target1));
    }
}

class solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        if(target < nums[l] || target > nums[r]){
            return -1;
        }
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

        }
        if(nums[l] != target){
            return -1;
        }
        else{
            return l;
        }

    }
}