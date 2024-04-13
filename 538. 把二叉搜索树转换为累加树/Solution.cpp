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
    int pre = 0;
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
    void traversal(TreeNode* root){
        if(!root) return;
        traversal(root->right);
        root->val += pre;
        pre = root->val;
        traversal(root->left);
    }
};