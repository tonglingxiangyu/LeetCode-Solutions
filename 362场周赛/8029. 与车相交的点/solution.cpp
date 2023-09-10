class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
            取交集合并区间：[min(l1​,l2​),max(r1​,r2​)]

            当我们遍历到区间 [li,ri][l_i, r_i][li​,ri​] 时：
            1.如果 ri​<left，说明 [li​,ri​] 与 S 不重叠并且在其左侧，我们可以直接将 [li​,ri​] 加入答案；
            2.如果 li>right，说明[li​,ri​] 与 S 不重叠并且在其右侧，我们可以直接将 [li​,ri​] 加入答案；
            3.如果上面两种情况均不满足，说明 [li​,ri​] 与 S 重叠，我们无需将 [li​,ri​] 加入答案。此时，我们需要将 S 与 [li​,ri​] 合并，即将 S 更新为其与 [li​,ri​] 的并集。
            当我们遇到第一个 满足 li​>right 的区间时，说明以后遍历到的区间不会与 S 重叠，并且它们左端点一定会大于 S 的左端点。此时我们就可以将 S 加入答案。特别地，如果不存在这样的区间，我们需要在遍历结束后，将 S 加入答案。
        */

        vector<vector<int>> res;
        int flag = 0; // s是否已经加入
        for(auto block : intervals){
            if(block[0] > newInterval[1] && flag == 0){ //第一次碰到 li>right 时，将s加入
                res.push_back(newInterval);
                res.push_back(block);
                flag = 1;
            }
            else if(block[0] > newInterval[1]){
                res.push_back(block);
            }
            else if(block[1] < newInterval[0]){
                res.push_back(block);
            }
            else{ // 其余情况说明有交集
                newInterval[0] = min(block[0], newInterval[0]);
                newInterval[1] = max(block[1], newInterval[1]);
            }
        }
        if(flag == 0){ // 如果s还没加入则加入向量中
            res.push_back(newInterval);
        }
        return res;
    }
};