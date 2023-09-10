class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        /*
            由于可以往 8 个方向走，那么最快可以在max⁡{∣sx−fx∣,∣sy−fy∣}秒后到达终点（先斜着走再直走）
            特殊情况：如果起点和终点重合，那么 t=1 的情况是无法回到起点的；如果 t≠1，我们可以同样地在起点不断「绕圈」，最后回到起点。
        */
        int ans = 0;
        int x = abs(sx - fx);
        int y = abs(sy - fy);
        if(x > y){
            ans = x;
        }
        else ans = y;
        if(ans == 0 && t == 1) return false; // 如果起点和终点重合，那么 t=1 的情况无法回到起点
        else return ans <= t;
    }
};