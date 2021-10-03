/*
 * @lc app=leetcode id=520 lang=java
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (54.20%)
 * Likes:    928
 * Dislikes: 309
 * Total Accepted:    203.7K
 * Total Submissions: 375.9K
 * Testcase Example:  '"USA"'
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * 
 * Given a string word, return true if the usage of capitals in it is right.
 * 
 * 
 * Example 1:
 * Input: word = "USA"
 * Output: true
 * Example 2:
 * Input: word = "FlaG"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 100
 * word consists of lowercase and uppercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean detectCapitalUse(String word) {
        if (word == null || word.isEmpty()) {
            return true;
        }

        if (word.charAt(0) >= 'A' && word.charAt(0) <= 'Z') {
            return allUpper(word.substring(1)) || allLower(word.substring(1));
        }

        return allLower(word.substring(1));
    }

    private boolean allUpper(String s) {
        for (char c : s.toCharArray()) {
            if (c < 'A' || c > 'Z') {
                return false;
            }
        }

        return true;
    }

    private boolean allLower(String s) {
        for (char c : s.toCharArray()) {
            if (c < 'a' || c > 'z') {
                return false;
            }
        }

        return true;
    }
}
// @lc code=end

