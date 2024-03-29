import java.util.HashMap;

/*
 * @lc app=leetcode id=677 lang=java
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (56.86%)
 * Likes:    1037
 * Dislikes: 114
 * Total Accepted:    77.7K
 * Total Submissions: 136.6K
 * Testcase Example:  '["MapSum","insert","sum","insert","sum"]\n' +
  '[[],["apple",3],["ap"],["app",2],["ap"]]'
 *
 * Design a map that allows you to do the following:
 * 
 * 
 * Maps a string key to a given value.
 * Returns the sum of the values that have a key with a prefix equal to a given
 * string.
 * 
 * 
 * Implement the MapSum class:
 * 
 * 
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one.
 * int sum(string prefix) Returns the sum of all the pairs' value whose key
 * starts with the prefix.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * Output
 * [null, null, 3, null, 5]
 * 
 * Explanation
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);  
 * mapSum.sum("ap");           // return 3 (apple = 3)
 * mapSum.insert("app", 2);    
 * mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= key.length, prefix.length <= 50
 * key and prefix consist of only lowercase English letters.
 * 1 <= val <= 1000
 * At most 50 calls will be made to insert and sum.
 * 
 * 
 */

// @lc code=start
class MapSum {

    class Node {
        public Node() {
        }

        private int val = 0;
        private HashMap<Character, Node> cs = new HashMap<>();
        private int last = 0;
    }

    private Node root = new Node();

    public MapSum() {
        
    }
    
    public void insert(String key, int val) {
        Node p = root;
        p.val += val;
        for (char c : key.toCharArray()) {
            p = p.cs.computeIfAbsent(c, node -> new Node());
            p.val += val;
        }

        if (p.last != 0) {
            int sub = p.last;
            p = root;
            p.val -= sub;
            for (char c : key.toCharArray()) {
                p = p.cs.get(c);
                p.val -= sub;
            }
        }

        p.last = val;
    }
    
    public int sum(String prefix) {
        Node p = root;
        for (char c : prefix.toCharArray()) {
            p = p.cs.get(c);
            if (p == null) {
                return 0;
            }
        }

        return p.val;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
// @lc code=end

