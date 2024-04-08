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
    int traversal(TreeNode* root){
        if(root == NULL) return 0;
        int left_val = traversal(root->left);
        int mid_val = 0;
        if(root->left && !root->left->left && !root->left->right){
            mid_val = root->left->val;
        }
        int right_val = traversal(root->right);
        return left_val + mid_val + right_val;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root);
    }
};