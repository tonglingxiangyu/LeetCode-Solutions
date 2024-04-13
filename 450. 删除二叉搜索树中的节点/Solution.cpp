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
 
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root) return nullptr;
        if(root->val == key){
            if(root->left && root->right){
                TreeNode* r = root->right;
                while(r->left){
                    r = r->left;
                }
                r->left = root->left;
                return root->right;
            }
            else if(!root->left && !root->right){
                root = nullptr;
                return root;
            }
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
        }
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};