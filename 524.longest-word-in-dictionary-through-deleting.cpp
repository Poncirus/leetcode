/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (47.68%)
 * Likes:    552
 * Dislikes: 234
 * Total Accepted:    67.8K
 * Total Submissions: 140.2K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * Given a string and a string dictionary, find the longest string in the
 * dictionary that can be formed by deleting some characters of the given
 * string. If there are more than one possible results, return the longest word
 * with the smallest lexicographical order. If there is no possible result,
 * return the empty string.
 * 
 * Example 1:
 * 
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * Output: 
 * "apple"
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * Output: 
 * "a"
 * 
 * 
 * 
 * Note:
 * 
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        sort(d.begin(), d.end(), [](const string &lhs, const string &rhs) {
            if (lhs.size() == rhs.size())
                return lhs < rhs;
            return lhs.size() > rhs.size();
        });

        vector<int> count(d.size(), 0);

        map<char, vector<int>> m;

        for (int i = 0; i < d.size(); i++)
        {
            if (d[i].size() != 0)
            {
                m[d[i][0]].push_back(i);
            }
        }

        for (auto &c : s)
        {
            vector<int> list(m[c]);
            m[c].clear();
            for (auto &i : list)
            {
                count[i]++;
                if (count[i] != d[i].size())
                    m[d[i][count[i]]].push_back(i);
            }
        }

        for (int i = 0; i < d.size(); i++)
        {
            if (count[i] == d[i].size())
                return d[i];
        }

        return "";
    }
};
// @lc code=end
