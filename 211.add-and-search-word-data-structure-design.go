/*
 * @lc app=leetcode id=211 lang=golang
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (34.21%)
 * Likes:    1378
 * Dislikes: 73
 * Total Accepted:    156.5K
 * Total Submissions: 455.5K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */

// @lc code=start
type WordDictionary struct {
	sons [26]*WordDictionary
	end  int
}

/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{}
}

/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string) {
	for _, b := range word {
		idx := b - 'a'
		if this.sons[idx] == nil {
			this.sons[idx] = &WordDictionary{}
		}
		this = this.sons[idx]
	}

	this.end++
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (this *WordDictionary) Search(word string) bool {
	for i, b := range word {
		if b != '.' {
			idx := b - 'a'
			if this.sons[idx] == nil {
				return false
			}

			this = this.sons[idx]
		} else {
			for _, son := range this.sons {
				if son == nil {
					continue
				}

				this = son
				if i == len(word)-1 {
					if this.end > 0 {
						return true
					}
					continue
				}

				if this.Search(word[i+1:]) {
					return true
				}
			}

			return false
		}
	}

	if this.end > 0 {
		return true
	}

	return false
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
// @lc code=end

