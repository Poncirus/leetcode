/*
 * @lc app=leetcode id=598 lang=java
 *
 * [598] Range Addition II
 *
 * https://leetcode.com/problems/range-addition-ii/description/
 *
 * algorithms
 * Easy (54.16%)
 * Likes:    561
 * Dislikes: 747
 * Total Accepted:    71.6K
 * Total Submissions: 132.1K
 * Testcase Example:  '3\n3\n[[2,2],[3,3]]'
 *
 * You are given an m x n matrix M initialized with all 0's and an array of
 * operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented
 * by one for all 0 <= x < ai and 0 <= y < bi.
 * 
 * Count and return the number of maximum integers in the matrix after
 * performing all the operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 3, ops = [[2,2],[3,3]]
 * Output: 4
 * Explanation: The maximum integer in M is 2, and there are four of it in M.
 * So return 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 3, n = 3, ops =
 * [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: m = 3, n = 3, ops = []
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 4 * 10^4
 * 0 <= ops.length <= 10^4
 * ops[i].length == 2
 * 1 <= ai <= m
 * 1 <= bi <= n
 * 
 * 
 */

// @lc code=start
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int i = 0 ; i < ops.length; i++) {
            if (ops[i][0] < m) m = ops[i][0];
            if (ops[i][1] < n) n = ops[i][1];
        }
        return m * n;
    }
}
// @lc code=end

