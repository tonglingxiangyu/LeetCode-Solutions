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

// 递归版本
// class Solution {
// public:
//     void traveral(TreeNode* root, vector<int>& ans){
//         if(root == nullptr){
//             return;
//         }
//         ans.push_back(root->val);
//         traveral(root->left, ans);
//         traveral(root->right, ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         traveral(root, ans);
//         return ans;
//     }
// };

// 迭代版本
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root) st.push(root);
        else return ans;
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return ans;
    }
};