class Solution {
    LinkedList<Integer> path = new LinkedList<>();
    List<List<Integer>> ans = new ArrayList<>();
    int sum = 0;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        backTracking(candidates, target, 0);
        return ans;
    }

    private void backTracking(int[] candidates, int target, int startIndex){
        if(sum == target){
            ans.add(new ArrayList(path));
        }
        for(int i = startIndex; i < candidates.length; i++){
            if(sum + candidates[i] > target){
                break;
            }
            if(i > startIndex && candidates[i] == candidates[i-1]){
                continue;
            }
            sum += candidates[i];
            path.add(candidates[i]);
            backTracking(candidates, target, i+1);
            sum -= candidates[i];
            path.removeLast();
        }
    }
}