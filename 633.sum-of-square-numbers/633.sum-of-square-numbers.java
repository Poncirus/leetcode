import java.util.HashSet;

/*
 * @lc app=leetcode id=633 lang=java
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (34.63%)
 * Likes:    1077
 * Dislikes: 436
 * Total Accepted:    119.1K
 * Total Submissions: 344K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, decide whether there're two integers a and b
 * such that a^2 + b^2 = c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: c = 5
 * Output: true
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: c = 3
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: c = 4
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: c = 2
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: c = 1
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean judgeSquareSum(int c) {
        HashSet<Integer> s = new HashSet<>();
        for (int i = 0; i <= Math.sqrt(c); i++) {
            int t = i * i;
            s.add(t);
            if (s.contains(c - t)) {
                return true;
            }
        }

        return false;
    }
}
// @lc code=end

