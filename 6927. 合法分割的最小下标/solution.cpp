#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // 用哈希表得到每个数的重复次数
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }

        // 得到众数x以及重复次数total，并且左右两边的众数也是x
        auto iter = max_element(counter.begin(), counter.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            });
        int x = iter->first;
        int total = iter->second;
        int freq = 0;
        int n = nums.size();

        // 枚举找到满足条件的i
        for(int i = 0; i < n; i++){
            if(nums[i] == x){
                freq++;
            }
            if(freq * 2 > i + 1 && (total - freq) * 2 > n - i - 1)
                return i;
        }
        
        return -1;
    }
};

 
int main(){
    vector<int> nums = {1,2,2,2};

    Solution solution;
    int result = solution.minimumIndex(nums);
    cout << "result: " << result << endl;
}


