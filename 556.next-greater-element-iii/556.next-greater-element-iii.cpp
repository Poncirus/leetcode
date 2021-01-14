/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (31.04%)
 * Likes:    672
 * Dislikes: 194
 * Total Accepted:    42.3K
 * Total Submissions: 133.4K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        if (n < 10)
            return -1;
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long val = stol(str);
        if (val > INT_MAX || val <= n)
            return -1;
        return val;
    }
};
// @lc code=end
