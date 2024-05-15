class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> path = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        boolean[] used = new boolean[nums.length];
        Arrays.fill(used, false);
        Arrays.sort(nums);
        backtracking(nums, used);
        return ans;
    }
    public void backtracking(int[] nums, boolean[] used){
        if(path.size() == nums.length){
            ans.add(new ArrayList<>(path));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(i > 0 && used[i-1] == false && nums[i] == nums[i-1]){
                continue;
            }
            if(used[i] == false){
                path.add(nums[i]);
                used[i] = true;
                backtracking(nums, used);
                path.removeLast();
                used[i] = false;
            }
        }
    }
}