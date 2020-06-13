/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (32.81%)
 * Likes:    1302
 * Dislikes: 149
 * Total Accepted:    97.3K
 * Total Submissions: 291.6K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        map<char, vector<int>> f;
        map<char, vector<int>> l;

        vector<int> empty;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if (word.size() == 0)
            {
                empty.push_back(i);
                continue;
            }
            f[word[0]].push_back(i);
            l[word[word.size() - 1]].push_back(i);
        }

        vector<vector<int>> res;

        for (auto p = f.begin(); p != f.end(); p++)
        {
            for (auto q = p->second.begin(); q < p->second.end(); q++)
            {
                for (auto r = l[p->first].begin(); r < l[p->first].end(); r++)
                {
                    if (*q != *r && isPali(words[*q] + words[*r]))
                        res.push_back(vector<int>{*q, *r});
                }
            }
        }

        if (empty.size() != 0)
        {
            for (int s = 0; s < words.size(); s++)
            {
                if (isPali(words[s]))
                {
                    for (auto p = empty.begin(); p < empty.end(); p++)
                    {
                        if (*p != s)
                        {
                            res.push_back(vector<int>{*p, s});
                            res.push_back(vector<int>{s, *p});
                        }
                    }
                }
            }
        }

        return res;
    }

private:
    bool isPali(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};
// @lc code=end
