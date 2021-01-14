/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (47.86%)
 * Likes:    376
 * Dislikes: 814
 * Total Accepted:    75K
 * Total Submissions: 156K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10^n.
 * 
 * 
 * Example:
 * 
 * 
 * Input: 2
 * Output: 91 
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, 
 * excluding 11,22,33,44,55,66,77,88,99
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        int res[] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691};
        if (n >= 10)
            return res[10];

        return res[n];
    }
};
// @lc code=end
