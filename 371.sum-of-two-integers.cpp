/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.65%)
 * Likes:    1188
 * Dislikes: 2146
 * Total Accepted:    184.2K
 * Total Submissions: 363.5K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        int trigger = a & b;
        int ret = a ^ b;
        while (trigger)
        {
            int temp = (trigger & 0xffffffff) << 1; //not a problem anymore!
            trigger = temp & ret;
            ret ^= temp;
        }
        return ret;
    }
};
// @lc code=end
