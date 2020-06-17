/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (59.65%)
 * Likes:    787
 * Dislikes: 1188
 * Total Accepted:    354.3K
 * Total Submissions: 575.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, bool> m;
        vector<int> res;
        for (auto p = nums1.begin(); p < nums1.end(); p++)
        {
            m[*p] = true;
        }

        for (auto p = nums2.begin(); p < nums2.end(); p++)
        {
            if (m[*p])
            {
                res.push_back(*p);
                m[*p] = false;
            }
        }

        return res;
    }
};
// @lc code=end
