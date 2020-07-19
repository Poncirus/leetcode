/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * algorithms
 * Hard (40.54%)
 * Likes:    714
 * Dislikes: 104
 * Total Accepted:    61.7K
 * Total Submissions: 142.5K
 * Testcase Example:  '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
 *
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array.
 * 
 * Example:
 * 
 * Input:
 * ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 * 
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 * 
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 * "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat"
 * can be concatenated by "rat", "cat", "dog" and "cat".
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given array will not exceed 10,000 
 * The length sum of elements in the given array will not exceed 600,000. 
 * All the input string will only include lower case letters.
 * The returned elements order does not matter. 
 * 
 * 
 */

// @lc code=start
class Solution
{
    vector<string> results;
    unordered_set<string> dict;
    int min_len = 1;
    bool isConcatenated(string const &word)
    {
        if (dict.count(word))
            return true;
        for (int i = min_len; i < word.size() - min_len + 1; ++i)
            if (dict.count(word.substr(0, i)) > 0 && isConcatenated(word.substr(i, word.size() - i)))
                return true;
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) { return lhs.size() < rhs.size(); });
        min_len = max(1ul, words.front().size());
        for (int i = 0; i < words.size(); dict.insert(words[i++]))
            if (words[i].size() >= min_len * 2 && isConcatenated(words[i]))
                results.push_back(words[i]);
        return results;
    }
};
// @lc code=end
