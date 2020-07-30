/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 *
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 *
 * algorithms
 * Hard (35.35%)
 * Likes:    551
 * Dislikes: 107
 * Total Accepted:    23.5K
 * Total Submissions: 64.3K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, return the number of all possible attendance
 * records with length n, which will be regarded as rewardable. The answer may
 * be very large, return it after mod 10^9 + 7.
 * 
 * A student attendance record is a string that only contains the following
 * three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A record is regarded as rewardable if it doesn't contain more than one 'A'
 * (absent) or more than two continuous 'L' (late).
 * 
 * Example 1:
 * 
 * Input: n = 2
 * Output: 8 
 * Explanation:
 * There are 8 records with length 2 will be regarded as rewardable:
 * "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
 * Only "AA" won't be regarded as rewardable owing to more than one absent
 * times. 
 * 
 * 
 * 
 * Note:
 * The value of n won't exceed 100,000.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int checkRecord(int n)
    {
        const int M = 1000000007;
        vector<vector<long>> dp(2, vector<long>(3, 0));
        dp = {{1, 1, 0}, {1, 0, 0}};
        for (int i = 1; i < n; ++i)
        {
            vector<vector<long>> tmp(2, vector<long>(3, 0));
            tmp[0][0] = ((dp[0][0] + dp[0][1] + dp[0][2]) % M);
            tmp[0][1] = dp[0][0] % M;
            tmp[0][2] = dp[0][1];
            tmp[1][0] = (((dp[0][0] + dp[0][1] + dp[0][2]) % M + (dp[1][0] + dp[1][1] + dp[1][2]) % M)) % M;
            tmp[1][1] = dp[1][0] % M;
            tmp[1][2] = dp[1][1] % M;
            dp = tmp;
        }
        long res = 0;
        for (int A = 0; A < 2; ++A)
        {
            for (int L = 0; L < 3; ++L)
            {
                res += dp[A][L] % M;
            }
        }
        return res % M;
    }
};
// @lc code=end
