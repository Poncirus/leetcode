/*
 * @lc app=leetcode id=208 lang=golang
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (44.05%)
 * Likes:    2432
 * Dislikes: 44
 * Total Accepted:    247.2K
 * Total Submissions: 559.1K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

// @lc code=start
type Trie struct {
    s [26]*Trie
	e  int
}


/** Initialize your data structure here. */
func Constructor() Trie {
    return Trie{}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    for _, v := range word {
        if this.s[v-'a'] == nil {
            this.s[v-'a'] = &Trie{}
        }
        this = this.s[v-'a']
    }
    this.e++
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    for _, v := range word {
        if this.s[v-'a'] == nil {
            return false
        }

        this = this.s[v-'a']
    }

    if this.e > 0 {
        return true
    }

    return false
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    for _, v := range prefix {
        if this.s[v-'a'] == nil {
            return false
        }

        this = this.s[v-'a']
    }

    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end

