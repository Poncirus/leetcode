/*
 * @lc app=leetcode id=680 lang=java
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (37.88%)
 * Likes:    3419
 * Dislikes: 210
 * Total Accepted:    338K
 * Total Submissions: 891.4K
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aba"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abc"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean validPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j && s.charAt(i) == s.charAt(j)) {
            i++;
            j--;
        }

        if (i >= j) {
            return true;
        }

        return palindrome(s, i + 1, j) || palindrome(s, i, j - 1);
    }

    private boolean palindrome(String s, int i, int j) {
        while (i < j && s.charAt(i) == s.charAt(j)) {
            i++;
            j--;
        }

        return i >= j;
    }
}
// @lc code=end

