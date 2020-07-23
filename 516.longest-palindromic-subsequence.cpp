/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (50.65%)
 * Likes:    1981
 * Dislikes: 178
 * Total Accepted:    119.3K
 * Total Submissions: 225.6K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input:
 * 
 * 
 * "bbbab"
 * 
 * Output:
 * 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * 
 * Example 2:
 * Input:
 * 
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n));
        return longestPalindromeSubseq(0, n - 1, s, mem);
    }
    int longestPalindromeSubseq(int l, int r, string &s, vector<vector<int>> &mem)
    {
        if (l == r)
            return 1;
        if (l > r)
            return 0;
        if (mem[l][r])
            return mem[l][r];
        return mem[l][r] = s[l] == s[r] ? 2 + longestPalindromeSubseq(l + 1, r - 1, s, mem) : max(longestPalindromeSubseq(l + 1, r, s, mem), longestPalindromeSubseq(l, r - 1, s, mem));
    }
};
// @lc code=end
