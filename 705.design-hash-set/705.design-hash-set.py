#
# @lc app=leetcode id=705 lang=python3
#
# [705] Design HashSet
#
# https://leetcode.com/problems/design-hashset/description/
#
# algorithms
# Easy (67.16%)
# Likes:    3830
# Dislikes: 313
# Total Accepted:    456.5K
# Total Submissions: 679.3K
# Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
#
# Design a HashSet without using any built-in hash table libraries.
# 
# Implement MyHashSet class:
# 
# 
# void add(key) Inserts the value key into the HashSet.
# bool contains(key) Returns whether the value key exists in the HashSet or
# not.
# void remove(key) Removes the value key in the HashSet. If key does not exist
# in the HashSet, do nothing.
# 
# 
# 
# Example 1:
# 
# 
# Input
# ["MyHashSet", "add", "add", "contains", "contains", "add", "contains",
# "remove", "contains"]
# [[], [1], [2], [1], [3], [2], [2], [2], [2]]
# Output
# [null, null, null, true, false, null, true, null, false]
# 
# Explanation
# MyHashSet myHashSet = new MyHashSet();
# myHashSet.add(1);      // set = [1]
# myHashSet.add(2);      // set = [1, 2]
# myHashSet.contains(1); // return True
# myHashSet.contains(3); // return False, (not found)
# myHashSet.add(2);      // set = [1, 2]
# myHashSet.contains(2); // return True
# myHashSet.remove(2);   // set = [1]
# myHashSet.contains(2); // return False, (already removed)
# 
# 
# Constraints:
# 
# 
# 0 <= key <= 10^6
# At most 10^4 calls will be made to add, remove, and contains.
# 
# 
#

# @lc code=start
class MyHashSet:
    
    def _my_hash(self, key: int):
       return hash(key) % 10000

    def __init__(self):
        self.mem = [[] for _ in range(10000)]

    def add(self, key: int) -> None:
       p = self.mem[self._my_hash(key)]
       if key not in p:
          p.append(key)

    def remove(self, key: int) -> None:
       p = self.mem[self._my_hash(key)]
       if key in p:
        p.remove(key)

    def contains(self, key: int) -> bool:
       p = self.mem[self._my_hash(key)]
       return key in p
       
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
# @lc code=end

