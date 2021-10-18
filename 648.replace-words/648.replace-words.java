/*
 * @lc app=leetcode id=648 lang=java
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (60.69%)
 * Likes:    1216
 * Dislikes: 148
 * Total Accepted:    81.8K
 * Total Submissions: 134.6K
 * Testcase Example:  '["cat","bat","rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other word to form another longer word - let's call this word successor. For
 * example, when the root "an" is followed by the successor word "other", we
 * can form a new word "another".
 * 
 * Given a dictionary consisting of many roots and a sentence consisting of
 * words separated by spaces, replace all the successors in the sentence with
 * the root forming it. If a successor can be replaced by more than one root,
 * replace it with the root that has the shortest length.
 * 
 * Return the sentence after the replacement.
 * 
 * 
 * Example 1:
 * Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled
 * by the battery"
 * Output: "the cat was rat by the bat"
 * Example 2:
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 * Example 3:
 * Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa
 * aaa aaa aaaaaa bbb baba ababa"
 * Output: "a a a a a a a a bbb baba a"
 * Example 4:
 * Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was
 * rattled by the battery"
 * Output: "the cat was rat by the bat"
 * Example 5:
 * Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this
 * solution is accepted"
 * Output: "it is ab that this solution is ac"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case letters.
 * 1 <= sentence.length <= 10^6
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each word in sentence is in the range [1, 1000]
 * Each two consecutive words in sentence will be separated by exactly one
 * space.
 * sentence does not have leading or trailing spaces.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        dictionary.sort((a, b) -> a.length() - b.length());

        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            for (String s : dictionary) {
                if (words[i].startsWith(s)) {
                    words[i] = s;
                    break;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            sb.append(" ");
            sb.append(words[i]);
        }

        return sb.substring(1);
    }
}
// @lc code=end

