class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {  
        vector<string> res;
        int num = nums.size();
        if(nums.empty()){
            return res;
        }
        if(num == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        
        int start, end, now;
        start = nums[0];
        now = start;
        for(int i = 1; i < num; i++){
            if(nums[i] != now + 1){
                end = now;
                if(end != start){
                    string s = to_string(start) + "->" + to_string(end);
                    res.push_back(s);
                }
                else{
                    string s = to_string(start);
                    res.push_back(s);
                }
                start = nums[i];
                now = start;
                if(i == num - 1 && start == nums[i]){
                    string s = to_string(start);
                    res.push_back(s);
                }
            }
            else if(i == num - 1){
                end = nums[i];
                string s = to_string(start) + "->" + to_string(end);
                res.push_back(s);
            }
            now = nums[i];
        }
        return res;
    }
};