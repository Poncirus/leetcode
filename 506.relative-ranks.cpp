/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (49.62%)
 * Likes:    257
 * Dislikes: 528
 * Total Accepted:    54.5K
 * Total Submissions: 108.3K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<int> order;
        for (int i = 0; i < nums.size(); i++)
            order.push_back(i);
        sort(order.begin(), order.end(), [&nums](const int &a, const int &b) { return nums[a] > nums[b]; });
        vector<string> res(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            switch (i)
            {
            case 0:
                res[order[i]] = "Gold Medal";
                break;
            case 1:
                res[order[i]] = "Silver Medal";
                break;
            case 2:
                res[order[i]] = "Bronze Medal";
                break;
            default:
                res[order[i]] = to_string(i + 1);
                break;
            }
        }
        return res;
    }
};
// @lc code=end
