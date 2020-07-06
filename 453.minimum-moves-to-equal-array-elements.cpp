/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (49.83%)
 * Likes:    550
 * Dislikes: 790
 * Total Accepted:    72.5K
 * Total Submissions: 145K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        auto min = min_element(nums.begin(), nums.end());

        int res = 0;
        for (auto p = nums.begin(); p < nums.end(); ++p)
        {
            res += *p - *min;
        }

        return res;
    }
};
// @lc code=end
