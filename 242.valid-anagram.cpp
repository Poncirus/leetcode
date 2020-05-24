/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (55.27%)
 * Likes:    1368
 * Dislikes: 135
 * Total Accepted:    537.3K
 * Total Submissions: 958K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int j = p;
            for (; j < t.size(); j++)
            {
                if (s[i] == t[j])
                {
                    t[j] = t[p];
                    break;
                }
            }

            if (j == t.size())
            {
                return false;
            }

            p++;
        }

        return true;
    }
};
// @lc code=end
