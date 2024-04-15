class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        backtracking(n, k, 1, 0);
        return ans;
    }
    private void backtracking(int n, int k, int start, int sum){
        if(sum > n) return;
        if(path.size() == k){
            if(sum == n) ans.add(new ArrayList<>(path));
            return;
        }
        for(int i = start; i <= 9-(k-path.size())+1; i++){
            path.add(i);
            sum += i;
            backtracking(n, k, i+1, sum);
            sum -= i;
            path.removeLast();
        }
    }
}