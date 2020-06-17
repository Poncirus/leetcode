/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.86%)
 * Likes:    1050
 * Dislikes: 39
 * Total Accepted:    65.2K
 * Total Submissions: 184.5K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    const int Zero = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int maxEnvelopes(vector<vector<int>> &env)
    {
        sort(env.begin(), env.end(), [](vector<int> &q, vector<int> &e) {
            return q[1] * q[0] < e[0] * e[1];
        });

        vector<int> maxInto(env.size(), 1);

        int maxNumber = 0;

        if (!env.empty())
        {
            maxNumber = maxInto[0];
        }

        for (int i = 1; i < env.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (env[j][0] < env[i][0] && env[j][1] < env[i][1])
                    maxInto[i] = max(maxInto[i], maxInto[j] + 1);
            }

            maxNumber = max(maxNumber, maxInto[i]);
        }

        return maxNumber;
    }
};
// @lc code=end
