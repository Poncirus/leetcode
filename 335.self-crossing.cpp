/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 *
 * https://leetcode.com/problems/self-crossing/description/
 *
 * algorithms
 * Hard (27.51%)
 * Likes:    129
 * Dislikes: 329
 * Total Accepted:    22K
 * Total Submissions: 79.5K
 * Testcase Example:  '[2,1,1,2]'
 *
 * You are given an array x of n positive numbers. You start at point (0,0) and
 * moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to
 * the south, x[3] metres to the east and so on. In other words, after each
 * move your direction changes counter-clockwise.
 * 
 * Write a one-pass algorithm with O(1) extra space to determine, if your path
 * crosses itself, or not.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ┌───┐
 * │   │
 * └───┼──>
 * │
 * 
 * Input: [2,1,1,2]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ┌──────┐
 * │      │
 * │
 * │
 * └────────────>
 * 
 * Input: [1,2,3,4]
 * Output: false 
 * 
 * 
 * Example 3:
 * 
 * 
 * ┌───┐
 * │   │
 * └───┼>
 * 
 * Input: [1,1,1,1]
 * Output: true 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isSelfCrossing(vector<int> &x)
    {
        x.insert(x.begin(), 4, 0);

        int len = x.size();
        int i = 4;

        // outer spiral
        for (; i < len && x[i] > x[i - 2]; i++)
            ;

        if (i == len)
            return false;

        // check border
        if (x[i] >= x[i - 2] - x[i - 4])
        {
            x[i - 1] -= x[i - 3];
        }

        // inner spiral
        for (i++; i < len && x[i] < x[i - 2]; i++)
            ;

        return i != len;
    }
};
// @lc code=end
