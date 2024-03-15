class Solution {
    public int[][] generateMatrix(int n) {
        int loop = n / 2, mid = n / 2;
        int[][] ans = new int[n][n];
        int count = 1;
        for(int l = 0; l < loop; l++){
            for(int i = 0; i < n-1-2*l; i++){
                ans[l][l+i] = count;
                count++;
            }
            for(int i = 0; i < n-1-2*l; i++){
                ans[l+i][n-1-l] = count;
                count++;
            }
            for(int i = 0; i < n-1-2*l; i++){
                ans[n-1-l][n-1-l-i] = count;
                count++;
            }
            for(int i = 0; i < n-1-2*l; i++){
                ans[n-1-l-i][l] = count;
                count++;
            }
        }
        if(n % 2 == 1){
            ans[mid][mid] = count;
        }
        return ans;
    }
}
