#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root != nullptr) st.push(root);
        else return ans;
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if(cur->left != nullptr) st.push(cur->left);
            if(cur->right != nullptr) st.push(cur->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};