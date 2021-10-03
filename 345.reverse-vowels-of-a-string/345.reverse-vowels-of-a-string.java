/*
 * @lc app=leetcode id=345 lang=java
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (46.13%)
 * Likes:    1254
 * Dislikes: 1631
 * Total Accepted:    308.3K
 * Total Submissions: 668.3K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 * 
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * cases.
 * 
 * 
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String reverseVowels(String s) {
        char[] b = s.toCharArray();
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(b[i])) {
                i++;
            }

            while (i < j && !isVowel(b[j])) {
                j--;
            }

            char tmp = b[i];
            b[i] = b[j];
            b[j] = tmp;
            i++;
            j--;
        }

        return new String(b);
    }

    private boolean isVowel(char c) {
        return c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c =='E' || c == 'I' || c == 'O' || c == 'U';
    }
}
// @lc code=end

