/*
 * @lc app=leetcode id=504 lang=java
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (46.95%)
 * Likes:    381
 * Dislikes: 177
 * Total Accepted:    75.1K
 * Total Submissions: 160K
 * Testcase Example:  '100'
 *
 * Given an integer num, return a string of its base 7 representation.
 * 
 * 
 * Example 1:
 * Input: num = 100
 * Output: "202"
 * Example 2:
 * Input: num = -7
 * Output: "-10"
 * 
 * 
 * Constraints:
 * 
 * 
 * -10^7 <= num <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        boolean op = false;
        if (num < 0) {
            op = true;
            num = -num;
        }

        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            sb.insert(0, (char)(num % 7 + '0'));
            num /= 7;
        }

        if (op) {
            sb.insert(0, '-');
        }

        return sb.toString();
    }
}
// @lc code=end

