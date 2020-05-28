/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (64.07%)
 * Likes:    1909
 * Dislikes: 144
 * Total Accepted:    153.5K
 * Total Submissions: 235.8K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && i + 1 != nums[i])
            {
                if (nums[i] == nums[nums[i] - 1])
                {
                    res.push_back(nums[i]);
                    nums[i] = -1;
                    break;
                }

                int t = nums[i];
                nums[i] = nums[t - 1];
                nums[t - 1] = t;
            }
        }

        return res;
    }
};
// @lc code=end
