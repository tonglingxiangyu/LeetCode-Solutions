class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, int left){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] < 0){
            return 0;
        }
        if(grid[x][y] == 2){
            return left == 0; // 必须访问完所有的0才返回1
        }

        grid[x][y] = -1;
        int ans = dfs(grid, x - 1, y, left - 1) + dfs(grid, x , y - 1, left - 1) + dfs(grid, x + 1, y, left - 1)
                    + dfs(grid, x , y + 1, left - 1);
        grid[x][y] = 0; //回溯，恢复现场
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        // count表示0的个数，sx、sy表示起点坐标
        int m = grid.size(), n = grid[0].size(), count = 0, sx, sy;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) count++;
                else if(grid[i][j] == 1) sx = i, sy = j;
            }
        }
        return dfs(grid, sx, sy, count + 1); //起点也算上
    }
};