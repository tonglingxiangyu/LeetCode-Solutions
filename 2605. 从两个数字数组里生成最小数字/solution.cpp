class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        /*
        如果 nums1​ 和 nums2​ 中有相同的数字，那么我们选出其中最小的那个即为答案，它是一个一位数。这一步可以使用哈希表解决：将 nums1​ 中的所有数字放入一个哈希集合，再依次枚举 nums2​ 中的每个数字，判断其是否在哈希集合中即可。
        */
        unordered_set<int> s(nums1.begin(), nums1.end());
        int ans = 10;
        for(int num : nums2){
            if(s.count(num)){
                ans = min(ans, num);
            }
        }
        if(ans == 10){
            int a = *min_element(nums1.begin(), nums1.end());
            int b = *min_element(nums2.begin(), nums2.end());
            ans = min(a * 10 + b, b * 10 + a);
        }
        return ans;
    }
};