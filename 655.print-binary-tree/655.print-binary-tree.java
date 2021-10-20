/*
 * @lc app=leetcode id=655 lang=java
 *
 * [655] Print Binary Tree
 *
 * https://leetcode.com/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (57.69%)
 * Likes:    82
 * Dislikes: 89
 * Total Accepted:    44.1K
 * Total Submissions: 76.3K
 * Testcase Example:  '[1,2]'
 *
 * Given the root of a binary tree, construct a 0-indexed m x n string matrix
 * res that represents a formatted layout of the tree. The formatted layout
 * matrix should be constructed using the following rules:
 * 
 * 
 * The height of the tree is height and the number of rows m should be equal to
 * height + 1.
 * The number of columns n should be equal to 2^height+1 - 1.
 * Place the root node in the middle of the top row (more formally, at location
 * res[0][(n-1)/2]).
 * For each node that has been placed in the matrix at position res[r][c],
 * place its left child at res[r+1][c-2^height-r-1] and its right child at
 * res[r+1][c+2^height-r-1].
 * Continue this process until all the nodes in the tree have been placed.
 * Any empty cells should contain the empty string "".
 * 
 * 
 * Return the constructed matrix res.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2]
 * Output: 
 * [["","1",""],
 * ["2","",""]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,null,4]
 * Output: 
 * [["","","","1","","",""],
 * ["","2","","","","3",""],
 * ["","","4","","","",""]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 2^10].
 * -99 <= Node.val <= 99
 * The depth of the tree will be in the range [1, 10].
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public List<List<String>> printTree(TreeNode root) {
        List<List<String>> result = new ArrayList<>();
        int row = getHight(root);
        int col = (int) Math.pow(2, row) - 1;
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < col; i++)
            ans.add("");
        for (int i = 0; i < row; i++)
            result.add(new ArrayList<>(ans));
        populateResult(root, result, 0, row, 0, col - 1);
        return result;
    }

    public void populateResult(TreeNode root, List<List<String>> result, int curRow, int totalRow, int i, int j) {
        if (root == null || curRow == totalRow)
            return;
        result.get(curRow).set((i + j) / 2, String.valueOf(root.val));
        populateResult(root.left, result, curRow + 1, totalRow, i, ((i + j) / 2) - 1);
        populateResult(root.right, result, curRow + 1, totalRow, ((i + j) / 2) + 1, j);
    }

    public int getHight(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(getHight(root.left), getHight(root.right));
    }
}
// @lc code=end
