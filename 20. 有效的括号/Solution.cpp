#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string lbrackets = "([{";
        string rbrackets = ")]}";
        for(int i = 0; i < s.size(); i++){
            if(lbrackets.find(s[i]) != string::npos){
                st.push(s[i]);
            }
            else if(rbrackets.find(s[i]) != string::npos){
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if(s[i] == ')' && t == '(') continue;
                else if(s[i] == ']' && t == '[') continue;
                else if(s[i] == '}' && t == '{') continue;
                else return false;
            }
        }
        return st.empty();
    }
};