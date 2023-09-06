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
    /*
        如果当前节点是最深叶子节点的最近公共祖先，那么它的左右子树的高度一定是相等的，否则高度低的那个子树的叶子节点深度一定比另一个子树的叶子节点的深度小，因此不满足条件。所以只需要dfs遍历找到左右子树高度相等的根节点即出答案。
        我们需要递归返回满足要求的节点以及深度，所以使用 pair 对作为返回值
        */
public:
    pair<TreeNode*, int> dfs(TreeNode* root, int depth){
        if(root == nullptr){
            return {nullptr, depth};
        }
        auto [left_node, left] = dfs(root->left, depth + 1); // 必须要 auto 指定类型
        auto [right_node, right] = dfs(root->right, depth + 1);
        if(left > right){ // 左子树更高
            return {left_node, left + 1};
        }
        if(left < right){ // 右子树更高
            return {right_node, right + 1};
        }
        return {root, right + 1}; // 一样高，这时候返回的root才不是nullptr，然后将这个root逐层递归给第一层的返回值
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 0).first; // 返回pair中的第一个值
    }
};