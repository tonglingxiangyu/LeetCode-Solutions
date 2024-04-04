#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();  
                st.pop();
                int t = 0;
                if(token == "+") t = t2 + t1;
                else if(token == "-") t = t2 - t1;
                else if(token == "*") t = t2 * t1;
                else if(token == "/") t = t2 / t1;
                st.push(t);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();       
    }
};