class Solution {
public:
    int minimumOperations(string num) {
        /*
            被25整除说明这个数是0、末尾是00、25、50、75
            以 50 为例说明：
            从右到左遍历 num，找到第一个 0。
            继续向左遍历，找到第一个 5，设其下标为 i。
            删除这个 5 右侧的所有非 0 数字，这样就得到了一个以 50 结尾的数字。
            删除次数为 n−i−2，例如示例 1 中 5 的下标是 i=3，需要删除 7−3−2=2 次。

            其余 00,25,75 的计算方式同理，取 n−i−2 的最小值作为答案。
            没有 0 的就返回n， 只有一个 0 的话就返回 n - 1
        */
        int n = num.length();
        // 构建一个匿名函数,用于查找每种情况下需要删除的元素个数。输入为查找的两个字符，输出为删除的元素个数
        auto f = [&](string tail){
            int i = num.rfind(tail[1]); // 查找第二个元素的位置
            if(i == string::npos || i == 0) return n; // 没有这个元素或者元素在第一位的情况
            i = num.rfind(tail[0], i - 1); // 从i - 1开始往左找第一个元素的位置
            if(i == string::npos) return n;
            return n - i - 2; // 删除掉第一个元素之后的除了第二个元素之外的其他元素
        };
        int a = n - (num.find('0') != string::npos); // 没有 0 的就返回n， 只有一个 0 的话就返回 n - 1
        return min({a, f("00"), f("25"), f("50"), f("75")}); // 使用 {} 来传入多个参数
        
    }
};