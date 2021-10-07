import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=501 lang=java
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (45.53%)
 * Likes:    1692
 * Dislikes: 476
 * Total Accepted:    127.5K
 * Total Submissions: 279.8K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given the root of a binary search tree (BST) with duplicates, return all the
 * mode(s) (i.e., the most frequently occurred element) in it.
 * 
 * If the tree has more than one mode, return them in any order.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,2]
 * Output: [2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
    public int[] findMode(TreeNode root) {
        if (root == null) {
            return new int[0];
        }
        int cur = 0;
        int count = 0;

        int r = 0;
        List<Integer> res = new ArrayList<>();

        Stack<TreeNode> s = new Stack<>();
        TreeNode p = root;

        while (p != null || !s.empty()) {
            while (p != null) {
                s.push(p);
                p = p.left;
            }

            if (!s.empty()) {
                p = s.pop();                

                if (cur == p.val) {
                    count++;
                } else {
                    cur = p.val;
                    count = 1;
                }

                if (count == r) {
                    res.add(cur);
                } else if (count > r) {
                    r = count;
                    res.clear();
                    res.add(cur);
                }

                p = p.right;
            }
        }

        return res.stream().mapToInt(i -> i).toArray();
    }
}
// @lc code=end

