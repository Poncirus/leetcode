/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (51.55%)
 * Likes:    1875
 * Dislikes: 115
 * Total Accepted:    527.9K
 * Total Submissions: 992.2K
 * Testcase Example:  '"leetcode"'
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase English letters.
 * 
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        for (auto &c : s)
        {
            m[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
