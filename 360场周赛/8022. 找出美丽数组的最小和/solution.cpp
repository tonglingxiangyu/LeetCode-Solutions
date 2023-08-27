class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        /*
        可以看出，当目标是target时，最优的取法是，1，2，3....，target/2，target, target + 1, target + 2.

        把 target 记作 k。
        对于 [1,k−1]内的数字，因为要求两数之和不能等于k，所以：
            1 和 k−1 只能选其中一个；
            2 和 k−2 只能选其中一个；
            3 和 k−3 只能选其中一个；
            ……
            一直到 ⌊k/2⌋，无论 k 是奇数还是偶数，它都可以选。
        
        m = min( ⌊k/2⌋ , n )
        接着再从 k 到 k+n-m-1 ，和为(m * (m + 1) + (k * 2 + n - m - 1) * (n - m)) // 2
        */

        long long m = min(target / 2, n);
        return (m * (m + 1) + (target * 2 + n - m - 1) * (n - m)) / 2;
    }
};