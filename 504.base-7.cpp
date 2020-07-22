/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (45.66%)
 * Likes:    231
 * Dislikes: 147
 * Total Accepted:    55.5K
 * Total Submissions: 120.2K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";

        bool neg = false;
        if (num < 0)
        {
            num = -num;
            neg = true;
        }

        string res;
        while (num != 0)
        {
            res = (char)('0' + num % 7) + res;
            num /= 7;
        }

        if (neg)
            res = '-' + res;

        return res;
    }
};
// @lc code=end
