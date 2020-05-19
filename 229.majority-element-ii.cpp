/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (34.28%)
 * Likes:    1423
 * Dislikes: 159
 * Total Accepted:    135.3K
 * Total Submissions: 388.4K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }

        int e1 = 0;
        int e2 = 0;
        int c1 = 0;
        int c2 = 0;

        for (auto p = nums.begin(); p < nums.end(); p++)
        {
            if (*p == e1)
            {
                c1++;
            }
            else if (*p == e2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                e1 = *p;
                c1 = 1;
            }
            else if (c2 == 0)
            {
                e2 = *p;
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        vector<int> res;

        int c = 0;
        for (auto p = nums.begin(); p < nums.end(); p++)
        {
            if (e1 == *p)
            {
                c++;
            }
        }
        if (c > nums.size() / 3)
        {
            res.push_back(e1);
        }

        c = 0;
        for (auto p = nums.begin(); p < nums.end(); p++)
        {
            if (e2 == *p)
            {
                c++;
            }
        }
        if (c > nums.size() / 3 && e1 != e2)
        {
            res.push_back(e2);
        }

        return res;
    }
};
// @lc code=end
