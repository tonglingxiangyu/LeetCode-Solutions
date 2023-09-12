class Solution {
    /*
    通过「深度优先搜索」需要记录每一个点是否被访问，我们用 vi[x] 来表示课程 x 是否被访问，初始时为 False。我们从编号小到大遍历全部节点，若节点 i 未被访问，则进入「深度优先搜索」流程：
    若当前节点 x 已被访问，则直接返回。
    若当前节点 x 未被访问，将访问状态设为已访问，然后继续对其全部后继节点递归进行「深度优先搜索」流程。将节点 x 置为其每一个后继节点 y 的先决条件，有 isPre[x][y]=True，以及对于每一个以 y 为先决条件的节点 t，节点 x 同样为 t 的先决条件，有 isPre[x][t]=True。

遍历完成后，「拓扑排序」完成，矩阵 isPre 计算完毕，然后我们遍历每一个查询，根据矩阵 isPre 即可得到每一个查询的结果。
    */
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<vector<bool>>& ispre, const int& cur){
        if(visited[cur]){
            return;
        }
        visited[cur] = true;
        for(auto i : graph[cur]){
            dfs(graph, visited, ispre, i);
            ispre[cur][i] = true;
            for(int j = 0; j < ispre.size(); j++){ // 让以 i 为前导的点也将 cur 作为前导，这里取并集，即本来就满足前导或者 i 是 j 的前导
                ispre[cur][j] = ispre[i][j] + ispre[cur][j];
            }
        }
        return;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses); // 用来存图
        for(auto i : prerequisites){
            graph[i[0]].push_back(i[1]);
        }
        vector<bool> visited(numCourses, false); // 是否被访问
        vector<vector<bool>> ispre(numCourses, vector<bool>(numCourses, false)); // 最后的先决条件数组
        // 一行一行的访问graph
        for(int i = 0; i < numCourses; i++){
            dfs(graph, visited, ispre, i);
        }

        vector<bool> ans;
        for(auto i : queries){
            ans.push_back(ispre[i[0]][i[1]]);
        }
        return ans;
    }
};