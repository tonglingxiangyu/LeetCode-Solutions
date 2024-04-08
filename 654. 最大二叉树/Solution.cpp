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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(0, nums.size()-1, nums);
    }
    TreeNode* traversal(int left, int right, vector<int>& nums){
        if(left > right) return nullptr;
        int maxindex = left;
        int Max = INT_MIN;
        for(int i = left; i <= right; i++){
            if(nums[i] > Max){
                Max = nums[i];
                maxindex = i;
            }
        }
        TreeNode* node = new TreeNode(nums[maxindex]);
        node->left = traversal(left, maxindex-1, nums);
        node->right = traversal(maxindex+1, right, nums);
        return node;
    }
};