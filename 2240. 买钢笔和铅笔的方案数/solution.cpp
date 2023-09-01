class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int max1 = total / cost1;
        int remain;
        long long ans = 0;
        for(int i = 0; i <= max1; i++){
            remain = total - cost1 * i;
            ans = ans + 1 + remain / cost2; // 可以直接计算出每次枚举的种类数
        }
        return ans;
    }
};