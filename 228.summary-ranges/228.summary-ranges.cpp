/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (38.27%)
 * Likes:    595
 * Dislikes: 503
 * Total Accepted:    161.7K
 * Total Submissions: 416.3K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        char buf[32];

        for (auto p = nums.begin(); p < nums.end(); p++)
        {
            string s = to_string(*p);

            if (p + 1 < nums.end() && *(p + 1) == *(p) + 1)
            {
                s += "->";
                while (p + 1 < nums.end() && *(p + 1) == *(p) + 1)
                {
                    p = p + 1;
                }
                s += to_string(*p);
            }

            res.push_back(s);
        }

        return res;
    }
};
// @lc code=end
