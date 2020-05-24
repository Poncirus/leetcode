/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (59.62%)
 * Likes:    1308
 * Dislikes: 94
 * Total Accepted:    133.3K
 * Total Submissions: 220.7K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0, x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            sum ^= nums[i];
        }

        sum = sum & ~(sum - 1);

        for (int i = 0; i < n; i++)
        {
            if (sum & nums[i])
                x ^= nums[i];
            else
                y ^= nums[i];
        }

        vector<int> v{x, y};

        return v;
    }
};
// @lc code=end
