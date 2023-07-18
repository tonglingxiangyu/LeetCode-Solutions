#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
            定义二维数组dp[n][2]:
                dp[i][0] 表示第 i 天不持有可获得的最大利润；
                dp[i][1] 表示第 i 天持有可获得的最大利润（注意是第 i 天持有，而不是第 i 天买入）。
            状态转移方程：
            不持有：dp[i][0]=max(dp[i−1][0],dp[i−1][1]+prices[i]−fee) 对于今天不持有，可以从两个状态转移过来：1. 昨天也不持有；2. 昨天持有，今天卖出。两者取较大值。
            持有：dp[i][1]=max(dp[i−1][1],dp[i−1][0]−prices[i]) 对于今天持有，可以从两个状态转移过来：1. 昨天也持有；2. 昨天不持有，今天买入。两者取较大值。
        */
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int> (2));
        
        // // 初始化第一列
        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];
        // for(int i = 1; i < n; i++){
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
        //     dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        // }
        // return dp[n-1][0];

        // 进行简化。dp[i][0] 和 dp[i][1] 只会从 dp[i−1][0]、dp[i−1][1] 转移而来，因此我们不必使用数组存储所有的状态，而是使用两个变量sell以及buy分别表示 dp[..][0]dp[..][1] 直接进行状态转移即可。
        int n = prices.size();
        int sell = 0;
        int buy = -prices[0];
        int tmp;
        for(int i = 0; i < n; i++){
            // tie(sell, buy) = pair(max(sell, buy + prices[i] - fee), max(buy, sell - prices[i]));
            tmp = max(sell, buy + prices[i] - fee);
            buy = max(buy, sell - prices[i]);
            sell = tmp; 
        }
        return sell;

    }
};

 
int main(){
    vector<int> prices={1, 3, 2, 8, 4, 9};

    Solution solution;
    int result = solution.maxProfit(prices);
    cout << "results: " << result << endl;
}


