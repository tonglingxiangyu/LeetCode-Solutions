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
    // 如果这里的s引用的是地址那么需要进行回溯，如果不是引用则不需要pop回溯
    void traversal(TreeNode* node, string s, vector<string>& ans){ 
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            s += to_string(node->val);
            ans.push_back(s);
            return;
        }
        s += to_string(node->val) + "->";
        traversal(node->left, s, ans);
        traversal(node->right, s, ans);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        vector<string> ans;
        traversal(root, s, ans);
        return ans;
    }
};