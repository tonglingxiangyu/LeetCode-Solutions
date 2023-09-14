class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        /*
            更加巧妙的做法是，站在国王的视角，计算有哪些皇后能被国王「看到」。
            想象成从国王的位置发射八个方向的射线，记录每条射线首次遇到的皇后。
        */
        vector<vector<int>> ans;
        const int directions[8][8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}; // 八个方向
        bool is_queen[8][8]{}; // 用数组效率更高，用 {} 进行初始化默认值为 false
        for(auto queen: queens){
            is_queen[queen[0]][queen[1]] = true;
        }
        // K 分别朝八个方向移动并记录第一次碰到的 queen
        for(auto d: directions){
            int x = king[0] + d[0];
            int y = king[1] + d[1];
            while(x >= 0 && x < 8 && y >= 0 && y < 8){
                if(is_queen[x][y]){
                    ans.push_back({x, y});
                    break;
                }
                x += d[0];
                y += d[1];
            }
        }
        return ans;
    }
};