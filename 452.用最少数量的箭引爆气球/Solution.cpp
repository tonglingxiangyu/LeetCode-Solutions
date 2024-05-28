#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
static bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end(), cmp);
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > points[i-1][1]) ans++;
            else{
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return ans;
    }
};;
