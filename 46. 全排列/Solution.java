class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> path = new ArrayList<>();
    boolean[] used;

    public List<List<Integer>> permute(int[] nums) {
        used = new boolean[nums.length];
        backtracking(nums, used);
        return ans;
    }
    public void backtracking(int[] nums, boolean[] used){
        if(path.size() == nums.length){
            ans.add(new ArrayList<>(path));
        }
        for(int i = 0; i < nums.length; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            path.add(nums[i]);
            backtracking(nums, used);
            path.removeLast();
            used[i] = false;
        }
    }
}