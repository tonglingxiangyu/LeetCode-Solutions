class Solution {
public:
/*
    实际上就是找到最多的不重叠子区间，类似给定一些会议求最大的不冲突会议数。我们按照有边界排序，然后将重叠的视作一个区间，然后用总的时间段数减去区间数
*/
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp); // 也可以用sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) { return u[1] < v[1]; });
        int ans = 1; // 记录非交叉的区间数
        int right = intervals[0][1]; // 记录当前区间的最小的右边界
        for(int i = 0; i < n; i++){
            if(right <= intervals[i][0]){
                right = intervals[i][1];
                ans++; //找到一个区间
            }
        }
        return n - ans; // 剩下的就是需要去除的时间段
    }
};