/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (56.36%)
 * Likes:    3557
 * Dislikes: 118
 * Total Accepted:    795.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        auto p = nums.begin();
        auto q = nums.begin();

        while (q != nums.end())
        {
            if (*q != 0)
            {
                *p = *q;
                p++;
                q++;
            }
            else
            {
                q++;
            }
        }

        while (p != nums.end())
        {
            *p = 0;
            p++;
        }
    }
};
// @lc code=end
