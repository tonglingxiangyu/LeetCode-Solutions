class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        我们固定子数组 [i,j] 的右端点 j 时，显然左端点 i 越大，子数组元素乘积越小。对于子数组 [i,j]，当左端点 i≥l1 时，所有子数组的元素乘积都小于 k，当左端点 i<l1​ 时，所有子数组的元素乘积都大于等于 k。那么对于右端点为 j+1 的所有子数组，它的左端点 i 就不需要从 0 开始枚举，因为对于所有 i<l1 的子数组，它们的元素乘积都大于等于 k。我们只要从 i=l1​ 处开始枚举，直到子数组 i=l2​ 时子数组 [l2,j+1] 的元素乘积小于 k，那么左端点 i≥l2​ 所有子数组的元素乘积都小于 k。
        */
        int ans = 0;
        int n = nums.size();
        int multi = 1;
        int i = 0;
        for(int j = 0; j < n; j++){
            multi *= nums[j];
            while(i <= j && multi >= k){
                multi /= nums[i];
                i++;
            }
            ans += j -i + 1; // i, j之间的能组成 j-i+1 个满足要求的子数组
        }

        return ans;
    }
};