#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // 排序之后用滑动窗口加双指针
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        for(int i = 0; i < n; i++){
            while(nums[i] - nums[left] > 2 * k){
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

 
int main(){
    vector<int> nums = {4, 6, 1, 2};
    int k = 2;

    Solution solution;
    int result = solution.maximumBeauty(nums);
    cout << "result: " << result << endl;
}


