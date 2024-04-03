class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        for(int i = 0; i < n-3; i++){
            if(nums[i] > 0 && nums[i] > target) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right]; // 需要用long型
                    if(sum > target) right--;
                    else if(sum < target) left++;
                    else{
                        ans.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        left++;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        right--;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        return ans;
    }
}