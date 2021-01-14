/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (55.65%)
 * Likes:    657
 * Dislikes: 1014
 * Total Accepted:    281K
 * Total Submissions: 501.2K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        int res = 0;
        while (num != 0)
        {
            res += num % 10;
            num /= 10;
        }

        if (res < 10)
            return res;

        return addDigits(res);
    }
};
// @lc code=end
