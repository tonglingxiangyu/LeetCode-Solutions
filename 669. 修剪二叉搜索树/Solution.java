/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
  public TreeNode trimBST(TreeNode root, int low, int high) {
      if(root == null) return null;
      if(root.val < low){
          TreeNode node = trimBST(root.right, low, high);
          return node;
      }
      if(root.val > high){
          TreeNode node = trimBST(root.left, low, high);
          return node;
      }
      root.left = trimBST(root.left, low, high);
      root.right = trimBST(root.right, low, high);
      return root;
  }
}