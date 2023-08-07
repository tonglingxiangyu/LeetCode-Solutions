class Solution {
public:
    void reverseString(vector<char>& s) {
        // 设置双指针将字符串的首位对换
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j){
            swap(s[i], s[j]);
            i++, j--;
        }
        return ;

    }
};