class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        for(int i = 1; i < prices.length; i++){
            int tmp = prices[i] - prices[i-1];
            if(tmp > 0) ans += tmp;
        }
        return ans;
    }
}