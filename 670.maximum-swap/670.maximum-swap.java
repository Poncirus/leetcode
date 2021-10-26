/*
 * @lc app=leetcode id=670 lang=java
 *
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (46.32%)
 * Likes:    1957
 * Dislikes: 113
 * Total Accepted:    123.5K
 * Total Submissions: 266.3K
 * Testcase Example:  '2736'
 *
 * You are given an integer num. You can swap two digits at most once to get
 * the maximum valued number.
 * 
 * Return the maximum valued number you can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
    public int maximumSwap(int num) {
        char[] digits = Integer.toString(num).toCharArray();

        int[] buckets = new int[10];
        for (int i = 0; i < digits.length; i++) {
            buckets[digits[i] - '0'] = i;
        }

        for (int i = 0; i < digits.length; i++) {
            for (int k = 9; k > digits[i] - '0'; k--) {
                if (buckets[k] > i) {
                    char tmp = digits[i];
                    digits[i] = digits[buckets[k]];
                    digits[buckets[k]] = tmp;
                    return Integer.valueOf(new String(digits));
                }
            }
        }

        return num;
    }
}
// @lc code=end
