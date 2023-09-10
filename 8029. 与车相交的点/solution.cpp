class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // 先将区间按照左端点排序，然后取并区间，最后计算结果
        vector<vector<int>> res;
        sort(nums.begin(), nums.end(), [](const auto& u, const auto& v){return u[0] < v[0];});
        res.push_back(nums[0]);
        int k = 0;
        for(int i = 1; i < nums.size(); i++){
            if(res[k][1] >= nums[i][0]){ // 有交集
                res[k][1] = max(res[k][1], nums[i][1]);
            }
            else{ // 无交集
                res.push_back(nums[i]);
                k++;
            }
        }
        int ans = 0;
        for(auto j : res){
            ans += j[1] - j[0] + 1;
        }
        return ans;
    }
};