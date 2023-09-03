class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            int n = s.length();
            int s1 = 0, s2 = 0;
            if(n % 2 == 0){
                for(int j = 0; j < n / 2; j++){
                    s1 += s[j] - '0';
                    s2 += s[n - j - 1] - '0';
                }
            }
            if(s1 == s2 && s1 != 0) ans++;
        }
        return ans;
    }
};