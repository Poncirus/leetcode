/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (53.05%)
 * Likes:    477
 * Dislikes: 251
 * Total Accepted:    112.7K
 * Total Submissions: 211.1K
 * Testcase Example:  '"USA"'
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * 
 * Note: The input will be a non-empty word consisting of uppercase and
 * lowercase latin letters.
 * 
 */

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() <= 1)
            return true;

        bool up = false;
        if (isUp(word[0]) && isUp(word[1]))
            up = true;

        for (int i = 1; i < word.size(); i++)
        {
            if ((up && !isUp(word[i])) || (!up && isUp(word[i])))
                return false;
        }

        return true;
    }

    bool isUp(char c)
    {
        return 'A' <= c && c <= 'Z';
    }
};
// @lc code=end
