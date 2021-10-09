/*
 * @lc app=leetcode id=600 lang=java
 *
 * [600] Non-negative Integers without Consecutive Ones
 *
 * https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
 *
 * algorithms
 * Hard (38.31%)
 * Likes:    954
 * Dislikes: 105
 * Total Accepted:    28.6K
 * Total Submissions: 74.5K
 * Testcase Example:  '5'
 *
 * Given a positive integer n, return the number of the integers in the range
 * [0, n] whose binary representations do not contain consecutive ones.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5
 * Output: 5
 * Explanation:
 * Here are the non-negative integers <= 5 with their corresponding binary
 * representations:
 * 0 : 0
 * 1 : 1
 * 2 : 10
 * 3 : 11
 * 4 : 100
 * 5 : 101
 * Among them, only integer 3 disobeys the rule (two consecutive ones) and the
 * other 5 satisfy the rule. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
    public int findIntegers(int n) {
        if (n < 3) {
            return n + 1;
        }

        int t = n;
        int z = 1;
        while (t != 1) {
            z = z << 1;
            t = t >> 1;
        }

        return findIntegers(z - 1) + findIntegers(Math.min((z >> 1) - 1, n - z));
    }
}
// @lc code=end

