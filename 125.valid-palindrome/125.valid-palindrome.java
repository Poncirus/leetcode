/*
 * @lc app=leetcode id=125 lang=java
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (39.71%)
 * Likes:    2484
 * Dislikes: 4373
 * Total Accepted:    990.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string s, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(String s) {
        char[] chs = s.toLowerCase().toCharArray();
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (!valid(chs[i]) && i < j) {
                i++;
            }

            while (!valid(chs[j]) && i < j) {
                j--;
            }

            if (chs[i] != chs[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    private boolean valid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
}
// @lc code=end

