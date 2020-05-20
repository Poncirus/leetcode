/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (30.99%)
 * Likes:    260
 * Dislikes: 583
 * Total Accepted:    47.2K
 * Total Submissions: 151.7K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * Example:
 * 
 * 
 * Input: 13
 * Output: 6 
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countDigitOne(int n)
    {
        int a, b, res;
        res = 0;
        for (long i = 1; i <= n; i = i * 10)
        {
            a = n / i;
            b = n % i;
            res += (a + 8) / 10 * i;
            if (a % 10 == 1)
            {
                res += b + 1;
            }
        }

        return res;
    }
};
// @lc code=end
