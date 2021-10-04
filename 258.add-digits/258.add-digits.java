/*
 * @lc app=leetcode id=258 lang=java
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (59.64%)
 * Likes:    1391
 * Dislikes: 1381
 * Total Accepted:    377K
 * Total Submissions: 632.2K
 * Testcase Example:  '38'
 *
 * Given an integer num, repeatedly add all its digits until the result has
 * only one digit, and return it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 38
 * Output: 2
 * Explanation: The process is
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you do it without any loop/recursion in O(1) runtime?
 * 
 */

// @lc code=start
class Solution {
    public int addDigits(int num) {
        while (num > 9) {
            int r = 0;
            while (num != 0) {
                r += num % 10;
                num /= 10;
            }
            num = r;
        }
        return num;
    }
}
// @lc code=end

