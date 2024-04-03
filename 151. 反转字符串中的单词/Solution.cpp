#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void removeExtraSpace(string& s){
        // 用快慢指针，快指针寻找需要留下的字符，慢指针指定位置
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++){
            if(s[fast] != ' '){
                while(fast < s.size() && s[fast] != ' '){
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
                s[slow] = ' ';
                slow++;
            }
        }
        s.resize(slow - 1);
    }

    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0;
        for(int i = 0; i <= n; i++){
            if(i == n || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
            
        }
        return s;
    }
};