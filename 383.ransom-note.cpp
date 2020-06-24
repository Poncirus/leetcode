/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (51.53%)
 * Likes:    609
 * Dislikes: 195
 * Total Accepted:    220.6K
 * Total Submissions: 416.8K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> m;
        for (size_t i = 0; i < ransomNote.size(); i++)
        {
            m[ransomNote[i]]++;
        }

        for (size_t i = 0; i < magazine.size(); i++)
        {
            m[magazine[i]]--;
        }

        for (auto p = m.begin(); p != m.end(); p++)
        {
            if (p->second > 0)
                return false;
        }

        return true;
    }
};
// @lc code=end
