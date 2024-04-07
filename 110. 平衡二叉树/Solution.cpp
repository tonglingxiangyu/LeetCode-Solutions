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
    int traversal(TreeNode* node){
        if(node == NULL) return 0;
        int left = traversal(node->left);
        int right = traversal(node->right);
        if(left == -1 || right == -1 || abs(left-right) > 1){
            return -1;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return traversal(root) == -1 ? false : true;
    }
};