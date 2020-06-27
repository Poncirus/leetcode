/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (49.59%)
 * Likes:    928
 * Dislikes: 80
 * Total Accepted:    139.3K
 * Total Submissions: 278.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> m;

        for (auto c : s)
        {
            m[c]++;
        }

        int res = 0;
        int single = 0;
        for (auto p = m.begin(); p != m.end(); ++p)
        {
            if (p->second % 2 == 1)
            {
                res += p->second - 1;
                single = 1;
            }
            else
            {
                res += p->second;
            }
        }

        return res + single;
    }
};
// @lc code=end
