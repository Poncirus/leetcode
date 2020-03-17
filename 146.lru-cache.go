/*
 * @lc app=leetcode id=146 lang=golang
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (30.12%)
 * Likes:    4735
 * Dislikes: 209
 * Total Accepted:    447.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */

// @lc code=start
type LRUCache struct {
    c int
    s [][]int
}


func Constructor(capacity int) LRUCache {
    return LRUCache{capacity, make([][]int, capacity, capacity)}
}


func (this *LRUCache) Get(key int) int {
    for i, v := range this.s {
        if v != nil && v[0] == key {
            this.s = append(this.s[:i], this.s[i+1:]...)
            this.s = append(this.s, v)
            return v[1]
        }
    }

    return -1
}


func (this *LRUCache) Put(key int, value int)  {
    for i, v := range this.s {
        if v != nil && v[0] == key {
            this.s = append(this.s[:i], this.s[i+1:]...)
            v[1] = value
            this.s = append(this.s, v)
            return
        }
    }

    this.s = this.s[1:]
    this.s = append(this.s, []int{key, value})
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

