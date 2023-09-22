class Solution {
public:
        /*
        看到「最大化最小值」或者「最小化最大值」就要想到二分答案，这是一个固定的套路。
        假设小偷偷取的房屋的最大金额为 y，显然 y∈[nums_min⁡,nums_max⁡]。下面是动态规划，记 f(y) 为在最大金额 y 的限制下，小偷可以偷取的最大房屋数目，f(y) 的计算方式为：
        记当前偷取的房屋数目为 count，遍历数组 nums，假设当前遍历的房屋的金额为 x，如果 x≤y 成立，且上一遍历的房屋没有被偷取，那么令偷取的房屋数目 count 加 1，表示该房屋被偷取。 遍历结束后 f(y)=count，显然 f(y) 是非递减函数。

        */
    int dynamic(vector<int>& nums, int mx){
        int n = nums.size();
        vector<int> f(n, 0);
        if(nums[0] <= mx){
            f[0] = 1;
            f[1] = 1;
        }
        else if(nums[1] <= mx){
            f[1] = 1;
        }
        
        for(int i = 2; i < n; i++){
            if(nums[i] <= mx){
                f[i] = max(f[i -1], f[i - 2] + 1);
            }
            else f[i] = f[i - 1];
        }
        return f[n - 1];
    }

    int minCapability(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while(left <= right){ // 闭区间，当left > right时退出循环，left即是答案
            int mid = left + (right - left) / 2;
            int t = dynamic(nums, mid);
            if(t >= k){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};