class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;
        sort(points.begin(), points.end(), [](const auto& u, const auto& v){return u[1] < v[1];});
        int right = points[0][1];
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(right < points[i][0]){
                right = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};