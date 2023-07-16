#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(n % (i+1) == 0) ans += nums[i] * nums[i];
        }
        return ans;
    }
};

 
int main(){
    vector<int> nums = {1,2,3,4};
    // int k = 2;

    Solution solution;
    int result = solution.sumOfSquares(nums);
    cout << "result: " << result << endl;
}


