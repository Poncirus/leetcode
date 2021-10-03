import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=415 lang=java
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (50.52%)
 * Likes:    2402
 * Dislikes: 457
 * Total Accepted:    376.8K
 * Total Submissions: 745.9K
 * Testcase Example:  '"11"\n"123"'
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 * 
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "11", num2 = "123"
 * Output: "134"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "456", num2 = "77"
 * Output: "533"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num1 = "0", num2 = "0"
 * Output: "0"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 and num2 consist of only digits.
 * num1 and num2 don't have any leading zeros except for the zero itself.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String addStrings(String num1, String num2) {
        List<Character> res = new ArrayList<>();
        int n1 = num1.length() - 1;
        int n2 = num2.length() - 1;
        int ad = 0;
        while (n1 >= 0 || n2 >= 0 || ad != 0) {
            int r = (n1 < 0 ? 0 : toI(num1.charAt(n1))) + (n2 < 0 ? 0 : toI(num2.charAt(n2))) + ad;
            ad = r / 10;
            res.add(0, (char)(r % 10 + '0'));
            n1--;
            n2--;
        }
        
        StringBuilder sb = new StringBuilder();
        for (char c : res) {
            sb.append(c);
        }
        return sb.toString();
    }

    private int toI(char c) {
        return c - '0';
    }
}
// @lc code=end

