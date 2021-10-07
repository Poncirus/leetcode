/*
 * @lc app=leetcode id=541 lang=java
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (49.88%)
 * Likes:    733
 * Dislikes: 1952
 * Total Accepted:    129.9K
 * Total Submissions: 260.5K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * Given a string s and an integer k, reverse the first k characters for every
 * 2k characters counting from the start of the string.
 * 
 * If there are fewer than k characters left, reverse all of them. If there are
 * less than 2k but greater than or equal to k characters, then reverse the
 * first k characters and left the other as original.
 * 
 * 
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public String reverseStr(String s, int k) {
        StringBuilder sb = new StringBuilder();
        boolean reverse = true;
        for (int p = 0; p < s.length(); p += k) {
            if (reverse) {
                for (int i = Math.min(p + k - 1, s.length() - 1); i >= p; i--) {
                    sb.append(s.charAt(i));
                }
            } else {
                sb.append(s.substring(p, Math.min(p + k, s.length())));
            }
            reverse = !reverse;
        }

        return sb.toString();
    }
}
// @lc code=end

