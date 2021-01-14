/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (63.83%)
 * Likes:    548
 * Dislikes: 660
 * Total Accepted:    111.7K
 * Total Submissions: 173K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++)
        {
            for (auto c : rows[i])
                dict[c - 'A'] = 1 << i;
        }
        vector<string> res;
        for (auto w : words)
        {
            int r = 7;
            for (char c : w)
            {
                r &= dict[toupper(c) - 'A'];
                if (r == 0)
                    break;
            }
            if (r)
                res.push_back(w);
        }
        return res;
    }
};
// @lc code=end
