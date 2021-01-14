/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (42.22%)
 * Likes:    1015
 * Dislikes: 35
 * Total Accepted:    73K
 * Total Submissions: 171.2K
 * Testcase Example:  '[[1,2]]'
 *
 * Given a collection of intervals, find the minimum number of intervals you
 * need to remove to make the rest of the intervals non-overlapping.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may assume the interval's end point is always bigger than its start
 * point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't
 * overlap each other.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &i)
    {
        int n = i.size();
        if (!n)
            return 0;
        sort(i.begin(), i.end(), [](vector<int> &v1, vector<int> &v2) {
            if (v1[1] == v2[1])
                return v1[0] < v2[0];
            return v1[1] < v2[1];
        });
        int ans = 1;
        int prev = i[0][1];
        for (int j = 1; j < n; j++)
        {
            int l = i[j][0];
            int r = i[j][1];
            if (l >= prev)
                ans++, prev = r;
        }
        return n - ans;
    }
};
// @lc code=end
