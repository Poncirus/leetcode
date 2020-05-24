/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (50.37%)
 * Likes:    1603
 * Dislikes: 1951
 * Total Accepted:    427.4K
 * Total Submissions: 837.8K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0;
        int sum = 0;
        int total = 0;
        for (; i < nums.size(); i++)
        {
            total += i;
            sum += nums[i];
        }

        return total + i - sum;
    }
};
// @lc code=end
