import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=687 lang=java
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (38.48%)
 * Likes:    2719
 * Dislikes: 590
 * Total Accepted:    128.3K
 * Total Submissions: 332.3K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not
 * pass through the root.
 * 
 * The length of the path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,5,1,1,5]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,4,5,4,4,5]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * The depth of the tree will not exceed 1000.
 * 
 * 
 */

// @lc code=start
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

    private int res = 0;

    public int longestUnivaluePath(TreeNode root) {
        if (root == null) {
            return 0;
        }

        recursion(root);
        return res - 1;
    }

    public int recursion(TreeNode root) {
        int path = 1;
        int lp = 0;
        int rp = 0;
        if (root.left != null) {
            int l = recursion(root.left);
            if (root.left.val == root.val) {
                lp = l;
            }
        }
        
        if (root.right != null) {
            int r = recursion(root.right);
            if (root.right.val == root.val) {
                rp = r;
            }
        }

        this.res = Math.max(this.res, path + lp + rp);
        return path + Math.max(lp, rp);
    }
}
// @lc code=end

