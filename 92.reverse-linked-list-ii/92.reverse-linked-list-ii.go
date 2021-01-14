/*
 * @lc app=leetcode id=92 lang=golang
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (37.26%)
 * Likes:    1834
 * Dislikes: 120
 * Total Accepted:    242.6K
 * Total Submissions: 650.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m == n {
		return head
	}

	s := &ListNode{}
	s.Next = head
	head = s

	for i := 0; i < m - 1; i++ {
		s = s.Next
	}

	ec := s.Next
	j := s.Next
	k := j.Next

	for i := 0; i < n - m; i++ {
		t := k.Next
		k.Next = j
		j = k
		k = t
	}

	s.Next = j
	ec.Next = k

	return head.Next
}
// @lc code=end

