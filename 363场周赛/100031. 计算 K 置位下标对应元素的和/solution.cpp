class Solution {
public:
    int countone(int n){
        int count = 0;
        while(n > 0){
            if(n & 1) count++;
            n >>= 1;
        }
        return count;
    }
    
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(countone(i) == k) ans += nums[i];
        }
        return ans;
    }
};