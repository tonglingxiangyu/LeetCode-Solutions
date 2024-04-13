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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        traversal(root, val);
        return root;
    }
    void traversal(TreeNode* root, int val){
        if(root == NULL){
            return;
        }
        if(val > root->val){
            if(!root->right){
                root->right = new TreeNode(val);
            }
            traversal(root->right, val);
        }
        if(val < root->val){
            if(!root->left){
                root->left = new TreeNode(val);
            }
            traversal(root->left, val);
        }
        return;
    }
};