/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (48.31%)
 * Likes:    904
 * Dislikes: 46
 * Total Accepted:    64.3K
 * Total Submissions: 130.3K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 10^4 balloons.
 * 
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps travelling up infinitely. The problem is to
 * find the minimum number of arrows that must be shot to burst all balloons.
 * 
 * Example:
 * 
 * 
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons
 * [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two
 * balloons).
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &p)
    {
        sort(p.begin(), p.end(), [](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int ans = 0, n = p.size();
        if (n == 0)
            return 0;
        ans = 1;
        int prev = p[0][1];
        for (int i = 1; i < n; i++)
        {
            if (prev >= p[i][0])
                continue;
            ans++;
            prev = p[i][1];
        }
        return ans;
    }
};
// @lc code=end
