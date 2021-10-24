import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=662 lang=java
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (39.57%)
 * Likes:    2880
 * Dislikes: 465
 * Total Accepted:    128.9K
 * Total Submissions: 325.6K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return the maximum width of the given
 * tree.
 * 
 * The maximum width of a tree is the maximum width among all levels.
 * 
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and rightmost non-null nodes), where the null nodes between the
 * end-nodes are also counted into the length calculation.
 * 
 * It is guaranteed that the answer will in the range of 32-bit signed
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,2,5,3,null,9]
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4
 * (5,3,null,9).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,3,null,5,3]
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2
 * (5,3).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,3,2,5]
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length
 * 2 (3,2).
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,3,2,5,null,null,9,6,null,null,7]
 * Output: 8
 * Explanation: The maximum width existing in the fourth level with the length
 * 8 (6,null,null,null,null,null,null,7).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 3000].
 * -100 <= Node.val <= 100
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
    
    private List<List<Long>> width = new ArrayList<>();

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        recursion(root, 0, 0);

        int res = 0;
        for (List<Long> l : width) {
            res = Math.max(res, (int)(l.get(1) - l.get(0) + 1));
        }
        return res;
    }

    private void recursion(TreeNode root, long num, int depth) {
        if (root == null) {
            return;
        }

        if (width.size() <= depth) {
            width.add(Arrays.asList(num, num));
        }

        width.get(depth).set(0, Math.min(width.get(depth).get(0), num));
        width.get(depth).set(1, Math.max(width.get(depth).get(1), num));

        recursion(root.left, num * 2, depth + 1);
        recursion(root.right, num * 2 + 1, depth + 1);
    }
}
// @lc code=end

