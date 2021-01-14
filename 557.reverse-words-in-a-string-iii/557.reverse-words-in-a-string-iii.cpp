/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (67.80%)
 * Likes:    1041
 * Dislikes: 87
 * Total Accepted:    205.5K
 * Total Submissions: 294.8K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        size_t p = 0, q = 0;
        while (p != s.size())
        {
            while (q != s.size() && s[q] != ' ')
            {
                q++;
            }

            reverse(s.begin() + p, s.begin() + q);

            while (q != s.size() && s[q] == ' ')
            {
                q++;
            }

            p = q;
        }

        return s;
    }
};
// @lc code=end
