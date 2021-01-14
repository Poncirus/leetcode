/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (50.70%)
 * Likes:    486
 * Dislikes: 152
 * Total Accepted:    50.8K
 * Total Submissions: 98.7K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> t;

        for (auto &s : timePoints)
        {
            t.push_back(convert(s));
        }

        sort(t.begin(), t.end());

        int sh = INT_MAX;
        for (auto p = t.begin() + 1; p < t.end(); p++)
        {
            sh = min(sh, *p - *(p - 1));
        }

        return min(sh, t[0] + 1440 - t[t.size() - 1]);
    }

    int convert(string t)
    {
        char *end;
        int hour = strtol(t.c_str(), &end, 10);
        end++;
        int min = strtol(end, &end, 10);
        return hour * 60 + min;
    }
};
// @lc code=end
