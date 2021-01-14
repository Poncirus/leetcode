/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (41.50%)
 * Likes:    1497
 * Dislikes: 151
 * Total Accepted:    125K
 * Total Submissions: 296.4K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aba"
 * Output: False
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        for (int d = 1; d <= s.size() / 2; d++)
        {
            if (s.size() % d != 0)
                continue;

            int i = d;
            string sub = s.substr(0, d);
            for (; i < s.size(); i += d)
            {
                if (sub != s.substr(i, d))
                    break;
            }

            if (i == s.size())
                return true;
        }

        return false;
    }
};
// @lc code=end
