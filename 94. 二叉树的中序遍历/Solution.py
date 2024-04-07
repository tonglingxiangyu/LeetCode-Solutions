# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 不同于先序遍历的存储结果的顺序，无法同时解决访问节点（遍历节点）和处理节点（将元素放进结果集）不一致的情况。
        stack = []
        ans = []
        if root:
            cur = root
        else:
            return ans
        
        while stack or cur: # 可能右子树存在栈为空
            if cur:
                stack.append(cur) # 一直存储左节点
                cur = cur.left    
            else:
                cur = stack.pop() # 左节点到尽头了开始存储答案，并且尝试访问右子树
                ans.append(cur.val)
                cur = cur.right
        return ans
    
# 针对三种遍历方式，使用迭代法写出统一风格的代码
#  无法同时解决访问节点（遍历节点）和处理节点（将元素放进结果集）不一致的情况。
#  那我们就将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。如何标记呢，就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。 这种方法也可以叫做标记法。
# class Solution {
#     public:
#         vector<int> inorderTraversal(TreeNode* root) {
#             vector<int> result;
#             stack<TreeNode*> st;
#             if (root != NULL) st.push(root);
#             while (!st.empty()) {
#                 TreeNode* node = st.top();
#                 if (node != NULL) {
#                     st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
#                     if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

#                     st.push(node);                          // 添加中节点
#                     st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

#                     if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
#                 } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
#                     st.pop();           // 将空节点弹出
#                     node = st.top();    // 重新取出栈中元素
#                     st.pop();
#                     result.push_back(node->val); // 加入到结果集
#                 }
#             }
#             return result;
#         }
#     };
