#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void getNext(int* next, string& s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            if(j >= 0 && s[j+1] != s[i]){
                j = next[j];
            }
            if(s[j+1] == s[i]){
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for(int i = 0; i < haystack.size(); i++){
            while(j >= 0 && needle[j+1] != haystack[i]){
                j = next[j];
            }
            if(needle[j+1] == haystack[i]){
                j++;
            }
            if(j == needle.size() - 1){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};