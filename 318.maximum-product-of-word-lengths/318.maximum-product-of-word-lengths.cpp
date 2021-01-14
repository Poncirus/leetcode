/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (50.20%)
 * Likes:    753
 * Dislikes: 69
 * Total Accepted:    95.5K
 * Total Submissions: 188K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * 
 * 
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * 
 * Example 3:
 * 
 * 
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        if (words.size() < 2)
            return 0;

        vector<unsigned> pat;
        for (auto p = words.begin(); p < words.end(); p++)
        {
            unsigned pattern = 0;
            for (auto c = p->begin(); c < p->end(); c++)
            {
                pattern |= (1 << (int)(*c - 'a'));
            }
            pat.push_back(pattern);
        }

        int res = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((pat[i] & pat[j]) == 0)
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }

        return res;
    }
};
// @lc code=end
