class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == 'i'){
                int k = ans.size();
                int j = 0;
                while((k - 1) > j){
                    swap(ans[k - 1], ans[j]);
                    j++, k--;
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};