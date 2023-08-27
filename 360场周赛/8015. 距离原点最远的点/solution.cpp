class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // '_'可以向左或向右，我们只需要计算全部向左res1和全部向右res2就能得到最远的距离
        int res1 = 0, res2 = 0;
        int res = 0;
        for(auto move : moves){
            if(move == 'L'){
                res1 -= 1;
                res2 -= 1;
            }
            else if(move == 'R'){
                res1 += 1;
                res2 += 1;
            }
            else if(move == '_'){
                res1 -= 1;
                res2 += 1;
            }
            res = max(abs(res1), abs(res2));
        }
        return res;
    }
};