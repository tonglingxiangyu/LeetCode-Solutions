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
    void traversal(TreeNode* root, vector<int>& tlist){
        if(root == NULL) return;
        traversal(root->left, tlist);
        tlist.push_back(root->val);
        traversal(root->right, tlist);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> tlist;
        traversal(root, tlist);
        for(int i = 0; i < tlist.size()-1; i++){
            if(tlist[i] >= tlist[i+1]) return false;
        }
        return true;
    }
};