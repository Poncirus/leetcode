import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
 * @lc app=leetcode id=676 lang=java
 *
 * [676] Implement Magic Dictionary
 *
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (56.10%)
 * Likes:    871
 * Dislikes: 169
 * Total Accepted:    56.5K
 * Total Submissions: 100.6K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n' +
  '[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
 *
 * Design a data structure that is initialized with a list of different words.
 * Provided a string, you should determine if you can change exactly one
 * character in this string to match any word in the data structure.
 * 
 * Implement the MagicDictionary class:
 * 
 * 
 * MagicDictionary() Initializes the object.
 * void buildDict(String[] dictionary) Sets the data structure with an array of
 * distinct strings dictionary.
 * bool search(String searchWord) Returns true if you can change exactly one
 * character in searchWord to match any string in the data structure, otherwise
 * returns false.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
 * [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
 * Output
 * [null, null, false, true, false, false]
 * 
 * Explanation
 * MagicDictionary magicDictionary = new MagicDictionary();
 * magicDictionary.buildDict(["hello", "leetcode"]);
 * magicDictionary.search("hello"); // return False
 * magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to
 * match "hello" so we return True
 * magicDictionary.search("hell"); // return False
 * magicDictionary.search("leetcoded"); // return False
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dictionary.length <= 100
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case English letters.
 * All the strings in dictionary are distinct.
 * 1 <= searchWord.length <= 100
 * searchWord consists of only lower-case English letters.
 * buildDict will be called only once before search.
 * At most 100 calls will be made to search.
 * 
 * 
 */

// @lc code=start
class MagicDictionary {

    private HashMap<Integer, HashMap<Integer, HashMap<Character, List<Integer>>>> dict = new HashMap<>();
    private int size = 0;

    public MagicDictionary() {
        
    }
    
    public void buildDict(String[] dictionary) {
        for (int i = 0; i < dictionary.length; i++) {
            int len = dictionary[i].length();
            for (int j = 0; j < dictionary[i].length(); j++) {
                dict.computeIfAbsent(len, m -> new HashMap<>()).computeIfAbsent(j, m -> new HashMap<>()).computeIfAbsent(dictionary[i].charAt(j), l -> new ArrayList<>()).add(i);
            }
        }

        this.size = dictionary.length;
    }
    
    public boolean search(String searchWord) {
        HashMap<Integer, HashMap<Character, List<Integer>>> m = dict.get(searchWord.length());
        if (m == null) {
            return false;
        }

        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int i = 0; i < size; i++) {
            counter.put(i, 0);
        }

        for (int i = 0; i < searchWord.length(); i++) {
            HashMap<Character, List<Integer>> t = m.get(i);
            if (t == null) {
                continue;
            }
            List<Integer> l = t.get(searchWord.charAt(i));
            if (l == null) {
                continue;
            }
            for (int j : l) {
                counter.put(j, counter.getOrDefault(j, 0) + 1);
            }
        }

        for (int i : counter.values()) {
            if (i == searchWord.length() - 1) {
                return true;
            }
        }

        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
// @lc code=end

